class Solution {
public:
int f(vector<int>& nums, int k,int n){
    int l=0;int r=0;unordered_map<int,int>mpp;int count=0;
    while(r<n){
     mpp[nums[r]]++;
     while(mpp.size()>k){
mpp[nums[l]]--;
if(mpp[nums[l]]==0)mpp.erase(nums[l]);
l++;
     }count+=r-l+1;r++;

    }return count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       int n=nums.size();
      return f(nums,k,n)-f(nums,k-1,n);

    }
     }; //brute force
// int n=nums.size();int cnt=0;
//         for(int i=0;i<n;i++){
//             unordered_map<int,int>mpp;
//            for(int j=i;j<n;j++){
//             mpp[nums[j]]++;
//             if(mpp.size()==k) cnt++;
//             else if(mpp.size()>k) break;
//            }
//         }
//         return cnt;