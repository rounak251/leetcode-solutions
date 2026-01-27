class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi=INT_MIN;int x=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){maxi=nums[i];x=i;}
        }
        for(int i=0;i<nums.size();i++){
            if(maxi<2*nums[i] && i!=x){
return -1;
            }
        }
        return x;
    }
};