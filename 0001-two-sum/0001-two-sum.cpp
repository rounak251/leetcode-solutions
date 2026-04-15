class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    //     unordered_map<int,int>mp;
    //     vector<int>arr;
    //     for(int i=0;i<nums.size();i++){
    //         int a=nums[i];
    //         int more=target-a;
    //         if(mp.find(more)!=mp.end()){
    //          arr.push_back(i);
    //          arr.push_back(mp[more]);
    //         }
    //         mp[a]=i;
    //     }
    //     return arr;
    // }
int n=nums.size();
  vector<pair<int,int>> arr;
        for(int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        int left = 0, right = n - 1;

        while(left < right){
            int sum = arr[left].first + arr[right].first;

            if(sum == target){
                return {arr[left].second, arr[right].second};
            }
            else if(sum > target){
                right--;
            }
            else{
                left++;
            }
        }

        return {};
    }
};