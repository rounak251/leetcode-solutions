class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size();
       // if(n==1)return 0;
      int i=n-1;
      
           while(   i>0 && nums[i]>nums[i-1]){
               i--;
              
            }
      
      return i;
    }
};