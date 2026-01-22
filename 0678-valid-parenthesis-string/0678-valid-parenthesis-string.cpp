class Solution {
public:


// bool f(int ind,int cnt,int n,string s,vector<vector<int>>&dp){
//   //  int cnt=0;
//     if(cnt<0)return false;
//     if(ind==n){
//         return (cnt==0);
//     } if(dp[ind][cnt]!=0)return dp[ind][cnt];
//     if(s[ind]=='(') return  dp[ind][cnt]= f(ind+1,cnt+1,n,s,dp);
//      if(s[ind]==')') return dp[ind][cnt]=f(ind+1,cnt-1,n,s,dp);
//       return dp[ind][cnt]=(f(ind+1,cnt+1,n,s,dp)||f(ind+1,cnt,n,s,dp)||f(ind+1,cnt-1,n,s,dp));

// }
    bool checkValidString(string s) {
        int n=s.size();
       // int cnt;
       // vector<vector<int>>dp(n,vector<int>(n,-1));
      // return f(0,0,n,s,dp);
      int min=0;int max=0;
      for(int i=0;i<n;i++){
if(s[i]=='(') {
    min++;max++;
}else if(s[i]==')'){
    min--;max--;
}else{
    min--;max++;
}
if(min<0)min=0;
      if(max<0)return false;
      }
      
      return min==0;
        
    }
};