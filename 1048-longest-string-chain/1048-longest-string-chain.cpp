class Solution {
public:
int t[1001][1001];
    bool ispred(string &s1, string &s2) {
        if (s2.length() != s1.length() + 1)
            return false;

        int i = 0, j = 0;

        while (i < s1.length() && j < s2.length()) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        return i == s1.length();
    }

    static bool lamda(string &a, string &b) {
        return a.length() < b.length();
    }

    int lis(vector<string>& words, int prev, int curr, int n) {

        if (curr == n)
            return 0;

        int taken = 0;
          if(prev!=-1 && t[prev][curr]!=-1)return t[prev][curr];
        if (prev == -1 || ispred(words[prev], words[curr])) {
            taken = 1 + lis(words, curr, curr + 1, n);
        }

        int not_taken = lis(words, prev, curr + 1, n);
  if(prev!=-1) t[prev][curr]=max(taken, not_taken);
        return max(taken, not_taken);
    }

    int longestStrChain(vector<string>& words) {
 memset(t,-1,sizeof(t));
        sort(words.begin(), words.end(), lamda);

        return lis(words, -1, 0, words.size());
    }
};