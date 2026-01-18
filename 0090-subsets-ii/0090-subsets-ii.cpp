class Solution {
public:
 void check(int i,vector<vector<int>>&ds,vector<int>&tq,int n,vector<int>& arr){
    if(i==n) {
        ds.push_back(tq);
 return;
    }
   
    tq.push_back(arr[i]);
     check(i+1,ds,tq,n,arr);
     tq.pop_back();
     while (i + 1 < n && arr[i] == arr[i + 1]) i++;
      check(i+1,ds,tq,n,arr);
}
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>>ds;
        vector<int>tq;
        check(0,ds,tq,n,arr);
        return ds;

    }
};