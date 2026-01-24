class Solution {
public:

// int f(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>&dp){
       
//     if(i==n-1) return triangle[i][j];
//  if(dp[i][j]!=-1)return dp[i][j];
   
//         int l=triangle[i][j]+f(i+1,j,n,triangle,dp);
//         int r=triangle[i][j]+f(i+1,j+1,n,triangle,dp);

//     return dp[i][j]=min(l,r);

// }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n=triangle.size();
//       // vector<vector<int>>dp(n,vector<int>(n,-1));
//       // return f(0,0,n,triangle,dp);
//        vector<vector<int>>dp(n,vector<int>(n,0));
//        for(int j=0;j<n;j++){
//         dp[n-1][j]=triangle[n-1][j];
//        }
//        for(int i=n-2;i>=0;i--){
//         for(int j=i;j>=0;j--){
//             long long int l = triangle[i][j] + dp[i + 1][j];
//                 long long int  r = triangle[i][j] + dp[i + 1][j + 1];
//                 dp[i][j]=min(l,r);
//         }
//        }
//        return dp[0][0];
//     }
// };
int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
      // vector<vector<int>>dp(n,vector<int>(n,-1));
      // return f(0,0,n,triangle,dp);
    //    vector<vector<int>>dp(n,vector<int>(n,0));
    vector<int>front(n,0);  vector<int>curr(n,0);
       for(int j=0;j<n;j++){
       front[j]=triangle[n-1][j];
       }
       for(int i=n-2;i>=0;i--){
      
        for(int j=i;j>=0;j--){
            long long int l = triangle[i][j] + front[j];
                long long int  r = triangle[i][j] + front[j + 1];
               curr[j]=min(l,r);
        }front=curr;
       }
       return front[0];
    }
};