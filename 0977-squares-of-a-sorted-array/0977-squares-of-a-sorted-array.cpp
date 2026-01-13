class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1;
        vector<int> ans(n);
        int k = n - 1;

        while (l <= r) {
            if (arr[l] * arr[l] > arr[r] * arr[r]) {
                ans[k] = arr[l] * arr[l];
                l++;
            } else {
                ans[k] = arr[r] * arr[r];
                r--;
            }
            k--;
        }
        return ans;
    }
};
