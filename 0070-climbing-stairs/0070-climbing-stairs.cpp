class Solution {
public:
int c(int n,vector<int>&dp){
    if(n==0)return 1;
     if(n==1)return 1;
if(dp[n]!=-1)return dp[n];
return dp[n]=c(n-1,dp)+c(n-2,dp);}
int climbStairs(int n){
    vector<int>dp(n+1,-1);
    return c(n,dp);
}

   
 }; 
//int climbStairs(int n) {
//         if(n==0)return 1;
//         if(n==1)return 1;
//         int prev=1;
//         int prev1=1;
//         for(int i=2;i<=n;i++){
//             int curri=prev+prev1;
//             prev1=prev;
//             prev=curri;
//         }
      
//         return prev;

//     }