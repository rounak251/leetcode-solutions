class Solution {
public:
    int expandFromCenter(string& s, int l, int r) {
        while (l >= 0 && r < (int)s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        
        return r - l - 1;  // length of palindrome
    }

    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int len1 = expandFromCenter(s, i, i);       // odd length, center at i
            int len2 = expandFromCenter(s, i, i + 1);   // even length, center between i, i+1
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;  // recover start index from center + length
            }
        }
        return s.substr(start, maxLen);
    }
};