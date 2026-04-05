class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) arr.push_back(nums[i]); // ✅
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) arr.push_back(nums[i]); // ✅
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == 2) arr.push_back(nums[i]); // ✅
        }

        for (int i = 0; i < n; i++) {
            nums[i] = arr[i];
        }
    }
};