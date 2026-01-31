class Solution {
public:
    int minimumK(vector<int>& nums) {

        int l = 1;
      int h = max(*max_element(nums.begin(), nums.end()), (int)nums.size());

        int ans = h;
        while (l <= h) {
            int k = l + (h - l) / 2;
            long long ops = 0;
            for (int x : nums) {
                ops += (x + k - 1) / k; 
                if (ops > 1LL * k * k) break;
            }
            if (ops <= 1LL * k * k) {
                ans = k;       h = k - 1;   
            } else {
                l = k + 1;  }  } return ans;
    }
};
