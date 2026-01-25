class Solution {
public:
// int f(int i,int j ,int n,vector<vector<int>>& matrix,vector<vector<int>>&dp){
//     if(j<0||j>=n)return +1e4;
//     if(i==0)return matrix[0][j];
//     if(dp[i][j]!=-1)return dp[i][j];
//       long long int s= matrix[i][j]+f(i-1,j,n,matrix,dp);
//         long long int l=matrix[i][j]+f(i-1,j-1,n,matrix,dp);
//          long long  int r=matrix[i][j]+f(i-1,j+1,n,matrix,dp);
//             return dp[i][j]=min(s,min(l,r));
// // }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         //int ans=1e4;

//        // vector<vector<int>>dp(n,vector<int>(n,-1));
//          vector<vector<int>>dp(n,vector<int>(n,0));
       
//         for(int j=0;j<n;j++){
//             dp[0][j]=matrix[0][j];
//         }
//      for(int i=1;i<n;i++){
//        for(int j=0;j<n;j++){
//                  long long int s= matrix[i][j]+dp[i-1][j];

//                  long long int l=matrix[i][j];
//                if(i-1>=0 && j-1>=0)  l+=dp[i-1][j-1];
//                else l+=1e4;
//                   long long  int r=matrix[i][j];
//                 if(i-1>=0 && j+1<n)   r+=dp[i-1][j+1];
//                 else r+=1e4;
//                 dp[i][j]=min(s,min(l,r));
//             }
//         }
//         int mins=1e4;
//         for(int j=0;j<n;j++){
//             mins =min(mins,dp[n-1][j]);
//         }return mins;
//      // ans = min(ans,f(n-1,j,n,matrix,dp));}return ans;
//     }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //int ans=1e4;

       // vector<vector<int>>dp(n,vector<int>(n,-1));
       //  vector<vector<int>>dp(n,vector<int>(n,0));
       vector<int>prev(n,0);vector<int>curr(n,0);
       
        for(int j=0;j<n;j++){
          prev[j]=matrix[0][j];
        }
     for(int i=1;i<n;i++){
       for(int j=0;j<n;j++){
                 long long int s= matrix[i][j]+prev[j];

                 long long int l=matrix[i][j];
               if(i-1>=0 && j-1>=0)  l+=prev[j-1];
               else l+=1e4;
                  long long  int r=matrix[i][j];
                if(i-1>=0 && j+1<n)   r+=prev[j+1];
                else r+=1e4;
                curr[j]=min(s,min(l,r));
            }prev=curr;
        }
        int mins=1e4;
        for(int j=0;j<n;j++){
            mins =min(mins,prev[j]);
        }return mins;
     // ans = min(ans,f(n-1,j,n,matrix,dp));}return ans;
    }
};