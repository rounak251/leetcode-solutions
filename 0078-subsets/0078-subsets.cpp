class Solution {
public:
 vector<vector<int>> ans;
void print(int ind,vector<int> &ds,vector<int>&nums,int n){
    if(ind==n){
       ans.push_back(ds);
        return;
}ds.push_back(nums[ind]);
print(ind+1,ds,nums,n);
ds.pop_back();
print(ind+1,ds,nums,n);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int> ds;
        print(0,ds,nums,n);
        return ans;
        
    }
};