class Solution {
public:
  void check(int i,vector<int>&ds,int n,int k,vector<int>&arr, vector<vector<int>>&ans){
    if(i==n){
        if(k==0) ans.push_back(ds);
        return;
    }if(arr[i]<=k){
    ds.push_back(arr[i]);
    check(i,ds,n,k-arr[i],arr,ans);
    ds.pop_back();
    }
    check(i+1,ds,n,k,arr,ans);

}
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n=arr.size();
        check(0,ds,n,k,arr,ans);
        return ans;
    }
};