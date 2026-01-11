class Solution {
public:
    int sign = 1;
    long long num = 0;

    void helper(string &s, int i) {
        if (i >= s.size() || !isdigit(s[i])) return;

        num = num * 10 + (s[i] - '0');

        if (sign * num >= INT_MAX) {
            num = INT_MAX;
            return;
        }
        if (sign * num <= INT_MIN) {
            num = -(long long)INT_MIN;
            return;
        }

        helper(s, i + 1);
    }

    int myAtoi(string s) {
        int i = 0;

        // skip leading spaces
        while (i < s.size() && s[i] == ' ') i++;

        // sign check
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        helper(s, i);
        return sign * num;
    }
};
