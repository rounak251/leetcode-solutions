class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        long long k = 1;
        for (int i = 0; i < 31; i++) {   // max power of 2 within int range
            if (k == n) return true;
            k *= 2;
        }
        return false;
    }
};
