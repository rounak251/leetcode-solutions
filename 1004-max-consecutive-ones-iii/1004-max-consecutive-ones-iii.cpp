class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int n= nums.size();
       int len=0;
       int maxlen=0;
       int l=0;
       int r=0;
       int zeros=0;
       while(r<n){
        if(nums[r]==0)zeros++;

        while(zeros>k){
            if(nums[l]==0) zeros--;
            l++;
        }
        if(zeros<=k){
            len=r-l+1;maxlen=max(maxlen,len);
            r++;
        }
       }
       return maxlen;
       } 
    
};