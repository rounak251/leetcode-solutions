#!/usr/bin/env python3
"""Backfill accepted LeetCode submissions into this repo, in LeetHub-3.0's layout.

Every solved problem becomes NNNN-slug/NNNN-slug.<ext> plus NNNN-slug/README.md
(the problem statement). Each problem is committed with its submission time, so
the GitHub contribution graph shows the day you actually solved it. The root
README gets LeetHub's topic tables, so the extension can keep appending to it.

Your login cookie comes from ~/.config/leetcode/cookies.env:
    LEETCODE_SESSION=...
    csrftoken=...        (optional)
(or from environment variables of the same names). They are never printed.

Usage:
    python3 scripts/sync_leetcode.py            # sync everything, then push
    python3 scripts/sync_leetcode.py --limit 3  # try the 3 oldest solves first
    python3 scripts/sync_leetcode.py --no-push
"""
import argparse
import json
import os
import re
import subprocess
import sys
import time
import urllib.error
import urllib.request
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
GITHUB_REPO = "rounak251/leetcode-solutions"
COOKIE_FILE = Path.home() / ".config/leetcode/cookies.env"
CACHE_DIR = Path.home() / ".cache/leetcode-sync"
REQUEST_GAP = 0.7  # seconds between uncached LeetCode requests

# Same map as LeetHub-3.0 (src/js/leetcode.js), keyed by lang.verboseName.
EXTENSIONS = {
    "C": ".c", "C++": ".cpp", "C#": ".cs", "Bash": ".sh", "Cangjie": ".cj",
    "Dart": ".dart", "Elixir": ".ex", "Erlang": ".erl", "Go": ".go",
    "Java": ".java", "JavaScript": ".js", "Javascript": ".js", "Kotlin": ".kt",
    "MySQL": ".sql", "MS SQL Server": ".sql", "Oracle": ".sql", "PHP": ".php",
    "Pandas": ".py", "PostgreSQL": ".sql", "Python": ".py", "Python3": ".py",
    "Racket": ".rkt", "Ruby": ".rb", "Rust": ".rs", "Scala": ".scala",
    "Swift": ".swift", "TypeScript": ".ts",
}

TOPICS_START = "<!---LeetCode Topics Start-->"
TOPICS_HEADER = "# LeetCode Topics"
TOPICS_END = "<!---LeetCode Topics End-->"
README_INTRO = (
    "# LeetCode Solutions\n\n"
    "My accepted LeetCode solutions, one folder per problem (code + problem statement). "
    "New solutions are pushed automatically by "
    "[LeetHub-3.0](https://github.com/raphaelheinz/LeetHub-3.0).\n\n"
)

SOLVED_QUERY = """
query($skip: Int!, $limit: Int!) {
  userProgressQuestionList(filters: {skip: $skip, limit: $limit, questionStatus: SOLVED}) {
    totalNum
    questions { frontendId title titleSlug }
  }
}"""

SUBMISSIONS_QUERY = """
query($slug: String!) {
  questionSubmissionList(offset: 0, limit: 20, questionSlug: $slug, status: 10) {
    submissions { id lang timestamp statusDisplay }
  }
}"""

DETAILS_QUERY = """
query($id: Int!) {
  submissionDetails(submissionId: $id) {
    code timestamp runtimeDisplay runtimePercentile memoryDisplay memoryPercentile
    lang { name verboseName }
    question { questionId questionFrontendId title titleSlug content difficulty }
    topicTags { name }
  }
}"""

TOPICS_QUERY = """
query($slug: String!) {
  question(titleSlug: $slug) { topicTags { name } }
}"""


def load_cookies():
    cookies = {}
    if COOKIE_FILE.exists():
        for line in COOKIE_FILE.read_text().splitlines():
            key, sep, value = line.partition("=")
            if sep and not key.lstrip().startswith("#"):
                cookies[key.strip()] = value.strip().strip("'\"")
    for key in ("LEETCODE_SESSION", "csrftoken"):
        cookies[key] = os.environ.get(key) or cookies.get(key)
    if not cookies["LEETCODE_SESSION"]:
        sys.exit(f"Missing LEETCODE_SESSION: put it in {COOKIE_FILE} (see the top of this script).")
    return cookies


class LeetCode:
    def __init__(self, cookies):
        self.headers = {
            "Content-Type": "application/json",
            "Referer": "https://leetcode.com/",
            "Origin": "https://leetcode.com",
            "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7)",
            "Cookie": f"LEETCODE_SESSION={cookies['LEETCODE_SESSION']}",
        }
        if cookies["csrftoken"]:
            self.headers["x-csrftoken"] = cookies["csrftoken"]
            self.headers["Cookie"] += f"; csrftoken={cookies['csrftoken']}"

    def request(self, url, body=None):
        data = json.dumps(body).encode() if body is not None else None
        for attempt in range(6):
            req = urllib.request.Request(url, data=data, headers=self.headers)
            try:
                with urllib.request.urlopen(req, timeout=30) as resp:
                    result = json.load(resp)
                time.sleep(REQUEST_GAP)
                return result
            except urllib.error.HTTPError as e:
                if e.code not in (429, 500, 502, 503, 504) or attempt == 5:
                    raise
            except urllib.error.URLError:
                if attempt == 5:
                    raise
            wait = 5 * 2 ** attempt
            print(f"  LeetCode is throttling, waiting {wait}s...", flush=True)
            time.sleep(wait)

    def graphql(self, query, variables=None):
        result = self.request("https://leetcode.com/graphql", {"query": query, "variables": variables or {}})
        if result.get("errors"):
            raise RuntimeError(f"LeetCode GraphQL error: {result['errors']}")
        return result["data"]

    def username(self):
        status = self.graphql("query { userStatus { isSignedIn username } }")["userStatus"]
        if not status["isSignedIn"]:
            sys.exit(f"LeetCode says you are not signed in: the cookies in {COOKIE_FILE} are wrong or expired.")
        return status["username"]

    def solved_slugs(self):
        slugs, skip = [], 0
        while True:
            page = self.graphql(SOLVED_QUERY, {"skip": skip, "limit": 100})["userProgressQuestionList"]
            if page is None:
                return self.solved_slugs_rest()
            slugs += [q["titleSlug"] for q in page["questions"]]
            skip += 100
            if skip >= page["totalNum"] or not page["questions"]:
                return slugs

    def solved_slugs_rest(self):
        pairs = self.request("https://leetcode.com/api/problems/all/")["stat_status_pairs"]
        return [p["stat"]["question__title_slug"] for p in pairs if p.get("status") == "ac"]

    def latest_accepted(self, slug):
        """Newest accepted submission per language for one problem."""
        subs = self.graphql(SUBMISSIONS_QUERY, {"slug": slug})["questionSubmissionList"]["submissions"] or []
        latest = {}
        for s in subs:
            if s["statusDisplay"] == "Accepted":
                if s["lang"] not in latest or int(s["timestamp"]) > int(latest[s["lang"]]["timestamp"]):
                    latest[s["lang"]] = s
        return list(latest.values())

    def details(self, submission_id):
        cached = CACHE_DIR / f"{submission_id}.json"
        if cached.exists():
            details = json.loads(cached.read_text())
        else:
            details = self.graphql(DETAILS_QUERY, {"id": int(submission_id)})["submissionDetails"]
            if details is None:
                raise RuntimeError(f"No details returned for submission {submission_id}")
        if not details.get("topicTags"):
            # submissionDetails leaves topicTags empty; LeetHub reads them from the question instead.
            slug = details["question"]["titleSlug"]
            details["topicTags"] = self.graphql(TOPICS_QUERY, {"slug": slug})["question"]["topicTags"]
        CACHE_DIR.mkdir(parents=True, exist_ok=True)
        cached.write_text(json.dumps(details))
        return details


def problem_name(question):
    """LeetHub's folder name: zero-padded frontend id + slug, e.g. 0001-two-sum."""
    qid = question["questionFrontendId"] or question["questionId"]
    return "0" * max(0, 4 - len(qid)) + f"{qid}-{question['titleSlug']}"


def git(*args, env=None):
    return subprocess.run(["git", *args], cwd=REPO, check=True, capture_output=True, text=True,
                          env={**os.environ, **(env or {})}).stdout


def percent(value):
    return f"{float(value):.2f}%" if value is not None else "n/a"


def commit_problem(d):
    q = d["question"]
    name = problem_name(q)
    ext = EXTENSIONS.get(d["lang"]["verboseName"])
    if ext is None:
        print(f"  skipping {name}: unknown language {d['lang']['verboseName']}")
        return None
    folder = REPO / name
    folder.mkdir(exist_ok=True)
    (folder / f"{name}{ext}").write_text(d["code"])
    readme = folder / "README.md"
    if not readme.exists():
        body = q["content"] or "<p>(Premium problem: statement not available.)</p>"
        readme.write_text(
            f'<h2><a href="https://leetcode.com/problems/{q["titleSlug"]}">'
            f'{q["questionFrontendId"]}. {q["title"]}</a></h2><h3>{q["difficulty"]}</h3><hr>{body}'
        )
    git("add", "--", name)
    if subprocess.run(["git", "diff", "--cached", "--quiet"], cwd=REPO).returncode == 0:
        return name  # already up to date
    ts = int(d["timestamp"])
    date = f"{ts} {time.strftime('%z', time.localtime(ts))}"
    message = (f"Time: {d['runtimeDisplay']} ({percent(d['runtimePercentile'])}), "
               f"Space: {d['memoryDisplay']} ({percent(d['memoryPercentile'])}) - LeetHub")
    git("commit", "-q", "-m", message, env={"GIT_AUTHOR_DATE": date, "GIT_COMMITTER_DATE": date})
    return name


def parse_topics(readme):
    """Existing LeetHub topic tables as {topic: [row, ...]}, in file order."""
    match = re.search(re.escape(TOPICS_START) + r"([\s\S]*)" + re.escape(TOPICS_END), readme)
    topics = {}
    if match:
        for section in match.group(1).split("## ")[1:]:
            lines = section.strip().split("\n")
            topics[lines[0].strip()] = [l for l in lines[3:] if l.startswith("| [")]
    return topics


def update_root_readme(problems):
    """Merge {name: (difficulty, [topics])} into the root README's LeetHub topic tables."""
    path = REPO / "README.md"
    readme = path.read_text() if path.exists() else README_INTRO
    before = readme.split(TOPICS_START)[0] if TOPICS_START in readme else readme
    after = readme.split(TOPICS_END, 1)[1] if TOPICS_END in readme else ""
    topics = parse_topics(readme)
    for name, (difficulty, tags) in sorted(problems.items()):
        row = f"| [{name}](https://github.com/{GITHUB_REPO}/tree/main/{name}/) | {difficulty} |"
        for tag in tags:
            rows = topics.setdefault(tag, [])
            if not any(f"[{name}]" in r for r in rows):
                rows.append(row)
    blocks = []
    for tag, rows in topics.items():
        rows = sorted(rows, key=lambda r: int(re.search(r"/(\d+)-", r).group(1)))
        blocks.append("\n".join([f"## {tag}", "| Problem Name | Difficulty |", "| ------- | ------- |", *rows]))
    path.write_text(before + "\n".join([TOPICS_START, TOPICS_HEADER, *blocks, TOPICS_END]) + after)
    git("add", "README.md")
    if subprocess.run(["git", "diff", "--cached", "--quiet"], cwd=REPO).returncode != 0:
        git("commit", "-q", "-m", f"Update topic list ({len(problems)} problems)")


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--limit", type=int, help="only sync this many problems (oldest solves first)")
    parser.add_argument("--no-push", action="store_true", help="commit locally but do not git push")
    args = parser.parse_args()

    lc = LeetCode(load_cookies())
    print(f"Signed in to LeetCode as {lc.username()}")
    slugs = lc.solved_slugs()
    print(f"{len(slugs)} solved problems; fetching latest accepted submission for each...")

    submissions = []
    for i, slug in enumerate(slugs, 1):
        for sub in lc.latest_accepted(slug):
            submissions.append(sub)
        if i % 25 == 0:
            print(f"  listed {i}/{len(slugs)}", flush=True)
    submissions.sort(key=lambda s: int(s["timestamp"]))
    if args.limit:
        submissions = submissions[: args.limit]

    problems = {}
    for i, sub in enumerate(submissions, 1):
        d = lc.details(sub["id"])
        name = commit_problem(d)
        if name:
            problems[name] = (d["question"]["difficulty"], [t["name"] for t in d["topicTags"] or []])
            print(f"[{i}/{len(submissions)}] {name}", flush=True)
    update_root_readme(problems)

    if not args.no_push:
        subprocess.run(["git", "push", "-u", "origin", "HEAD"], cwd=REPO, check=True)
    print(f"Done: {len(problems)} problems in {REPO}")


if __name__ == "__main__":
    main()
