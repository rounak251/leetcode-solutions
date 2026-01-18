class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long fmax = LLONG_MIN;
        long long smax = LLONG_MIN;
        long long tmax = LLONG_MIN;

        for (int x : nums) {
            if (x == fmax || x == smax || x == tmax)
                continue;

            if (x > fmax) {
                tmax = smax;
                smax = fmax;
                fmax = x;
            }
            else if (x > smax) {
                tmax = smax;
                smax = x;
            }
            else if (x > tmax) {
                tmax = x;
            }
        }

        return (tmax == LLONG_MIN) ? fmax : tmax;
    }
};
