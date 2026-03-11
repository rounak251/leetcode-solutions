class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n);
        vector<long long> suffix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        suffix[n-1] = 1; 
        for(int i = n-2; i >= 0; i--){
            if(suffix[i+1] > LLONG_MAX / nums[i+1]){
                suffix[i] = LLONG_MAX; 
            } else {
                suffix[i] = suffix[i+1] * nums[i+1];
            }
        }
        for(int i = 0; i < n; i++){
            long long leftSum = (i == 0) ? 0 : prefix[i-1];
            long long rightProduct = suffix[i];

            if(leftSum == rightProduct) return i;
        }

        return -1;
    }
};