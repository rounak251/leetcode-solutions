class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        int n = nums.size();

        // Step 1: Sort
        sort(nums.begin(), nums.end());

        // Step 2: Fix one element
        for(int i = 0; i < n - 2; i++) {

            // Skip duplicate i
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1;
            int r = n - 1;

           
            while(l < r) {

                int sum = nums[i] + nums[l] + nums[r];

                if(sum == 0) {

         ans.push_back({
                        nums[i],
                        nums[l],
                        nums[r]});
                      l++;
                    r--;
                    while(l < r && nums[l] == nums[l - 1])
                        l++;

                    while(l < r && nums[r] == nums[r + 1])
                        r--;
                }

                else if(sum < 0) l++;

                else   r--;
                }}
        return ans;
    }
};
 // int n = nums.size();
        // vector<vector<int>> ans;

        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         for(int k = j + 1; k < n; k++) {

        //             if(nums[i] + nums[j] + nums[k] == 0) {

        //                 vector<int> temp = {
        //                     nums[i],
        //                     nums[j],
        //                     nums[k]
        //                 };

        //                 sort(temp.begin(), temp.end());

        //                 ans.push_back(temp);
        //             }
        //         }
        //     }
        // }

        // sort(ans.begin(), ans.end());

        // ans.erase(unique(ans.begin(), ans.end()), ans.end());

        // return ans;