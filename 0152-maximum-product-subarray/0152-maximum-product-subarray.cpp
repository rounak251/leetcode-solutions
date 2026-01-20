class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1;int sufix=1;int n=nums.size();int maxproduct=INT_MIN;
        int cnt=0;if(n==1)return nums[0];
        
        for(int i=0;i<n;i++ ){
            if(prefix==0) prefix=1;
            if(sufix==0) sufix=1;
            prefix*=nums[i];
            sufix*=nums[n-i-1];
            maxproduct =max(maxproduct,max(prefix,sufix));

        }return maxproduct;
    }
};