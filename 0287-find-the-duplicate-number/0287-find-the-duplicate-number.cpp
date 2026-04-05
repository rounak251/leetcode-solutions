class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++){
        mp[nums[i]]++;
       }
       for(auto &v:mp){
        int a=v.first;
        int b=v.second;
        if(b>=2) return a;
       }
     return -1;
    }
};