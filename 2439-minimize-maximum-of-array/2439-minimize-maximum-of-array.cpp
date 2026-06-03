class Solution {
public:
bool isvalid(vector<int>&nums,int mid){
    int n=nums.size();
     vector<long long> arr(nums.begin(), nums.end());

    for(int i=0;i<n-1;i++){
         if(mid<arr[i])return false;//max>=num[i]
         long long buffer=mid-arr[i];
         arr[i+1]-=buffer;

    }
    return arr[n-1]<=mid;
}
    int minimizeArrayValue(vector<int>& nums) {
        int l=0;
        int r=*max_element(nums.begin(),nums.end());
        int result=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isvalid(nums,mid)){
                result=mid;r=mid-1;

            }else l=mid+1;
        }
        return result;
    }
};