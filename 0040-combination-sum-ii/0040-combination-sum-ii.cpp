class Solution {
public:
  void check(int i,vector<int>&ds,int n,int k,vector<int>&arr, vector<vector<int>>&ans){
       if(k==0){ ans.push_back(ds);
        return;
    }for(int j=i;j<n;j++){
        
        if(j>i && arr[j]==arr[j-1])continue;
        if(arr[j]>k)break;
ds.push_back(arr[j]);
    check(j+1,ds,n,k-arr[j],arr,ans);
    ds.pop_back();
    }
    
}
    vector<vector<int>> combinationSum2(vector<int>& arr, int k) {
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        vector<int>ds;
        int n=arr.size();
        check(0,ds,n,k,arr,ans);
        return ans;
    }
};