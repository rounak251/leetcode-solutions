class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n=nums.size();
      
        sort(nums.begin(),nums.end());
          int i=n-1;
        long long  sum=0;
        while(k>0){
            if(mul>0){
                sum+= 1LL*nums[i]*mul;
                mul--;
            }
            else sum+=nums[i];
            i--;
            k--;
        }
        return sum;
    }
};