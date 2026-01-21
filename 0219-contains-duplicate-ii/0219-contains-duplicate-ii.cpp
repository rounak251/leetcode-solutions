class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int n = nums.size();
        unordered_set<int> st;

        while (r < n) {

            // If current element already exists in window
            if (st.count(nums[r])) 
                return true;

            st.insert(nums[r]);

            // Maintain window size <= k
            if (r - l >= k) {
                st.erase(nums[l]);
                l++;
            }
            r++;
        }
        return false;
    }
};
