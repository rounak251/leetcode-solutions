class Solution {
public:


    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
      //  vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
       //vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
       vector<int>prev(sum+1,0);vector<int>curr(sum+1,0);
       prev[0]=curr[0]=true;
      // for(int i=0;i<n;i++) dp[i][0]=true;
     if(arr[0]<=sum) prev[arr[0]]=true;
        //  if(arr[0] <= sum) dp[0][arr[0]]=true;
       for(int index=1;index<n;index++){
           for(int target=1;target<=sum;target++){
                bool take=false;
      if(target>=arr[index]) take=prev[target-arr[index]];
      bool nottake=prev[target];
      curr[target]=(take | nottake);
           }prev=curr;
       }
        
        return prev[sum];
    // return   check(n-1,arr,sum,dp);
        
    }
    bool canPartition(vector<int>& arr) {
        int sums=0;
        for(int i=0;i<arr.size();i++){
            sums+=arr[i];
        } int sum=sums/2;
        if(sums%2!=0)return false;
        return isSubsetSum(arr,sum);
    }
};