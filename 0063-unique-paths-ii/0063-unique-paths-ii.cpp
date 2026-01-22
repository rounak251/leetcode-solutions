class Solution {
public:
int fuc(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& arr){
    if(i>=0&&j>=0&&arr[i][j]==1)return 0;
    if(i==0&&j==0) return 1;
    if(i<0||j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int up=fuc(i-1,j,dp,arr);
    int down=fuc(i,j-1,dp,arr);
    return dp[i][j]= up+down;
}
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m=arr.size();
        int n=arr[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
       return fuc(m-1,n-1,dp,arr);
    }
};