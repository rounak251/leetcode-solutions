class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int r = 0; // index for children
        int l = 0; // index for cookies

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while (l < m && r < n) {   // Fix: iterate cookies, stop if all children assigned
            if (s[l] >= g[r]) {    // cookie satisfies child
                r++;               // move to next child
            }
            l++;                   // move to next cookie
        }

        return r;  // number of content children
    }
};
