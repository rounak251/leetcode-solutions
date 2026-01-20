//space optimization
class Solution {
public:

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        //vector<int>dp(n,-1);
      int prev= nums[0];
    int prev2=0;
    //int neg=0;
    for(int i=1;i<n;i++){

    long long int pick=nums[i];
    if(i>1)pick+=prev2;
    long long int notpick= prev;
     int curri= max(pick,notpick);
     prev2=prev;
     prev=curri;
    }
    return prev;}
};

///sol with tablution
// class Solution {
// public:

//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1)return nums[0];
//         vector<int>dp(n,-1);
//        dp[0]= nums[0];
//     int neg=0;
//    // if(ind<0) return 0;
//     //if(dp[ind]!=-1) return dp[ind];
//     for(int i=1;i<n;i++){

//     long long int pick=nums[i];
//     if(i>1)pick+=dp[i-2];
//     long long int notpick= dp[i-1];
//      dp[i]= max(pick,notpick);
//     }
//     return dp[n-1];}
// };

//sol with memo
// class Solution {
// public:
// int f(int ind,vector<int>&nums,vector<int>&dp){
//     if(ind==0) return nums[ind];
//     if(ind<0) return 0;
//     if(dp[ind]!=-1) return dp[ind];
//     long long int pick=nums[ind]+f(ind-2,nums,dp);
//     long long int notpick= f(ind-1,nums,dp);
//     return dp[ind]= max(pick,notpick);
// }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>dp(n,-1);
//        return  f(n-1,nums,dp);
//     }
// };