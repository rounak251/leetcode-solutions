class Solution {
public:

    int findLongestChain(vector<vector<int>>& nums) {
       
 int  n=nums.size();
 sort(nums.begin(),nums.end());
        vector<int>t(n,1);
        int maxlis=1;
        for(int i=0;i<n;i++){
            for (int j=0;j<i;j++){
               if(nums[i][0]>nums[j][1]){
                t[i]=max(t[i],t[j]+1);
                maxlis=max(maxlis,t[i]);
               }
            }
        }
        return maxlis;}
        };
// class Solution {
// public:
// int n;
// int t[2501][2501];
// int solve(vector<vector<int>>& nums,int i,int p){
//     if(i>=n)return 0;
//     if(p!=-1 && t[i][p]!=-1) return t[i][p];
//     int take=0;
//     if(p==-1 || nums[p][1]<nums[i][0]){
//       take =1+solve(nums,i+1,i);}
//       int skip=solve(nums,i+1,p);
//       if(p!=-1)t[i][p]=max(take,skip);
//       return max(take,skip);
// }
//     int findLongestChain(vector<vector<int>>& nums) {
//         n=nums.size();
//         memset(t,-1,sizeof(t));
//         sort(nums.begin(),nums.end());
//          return solve(nums,0,-1);
//     }
// };