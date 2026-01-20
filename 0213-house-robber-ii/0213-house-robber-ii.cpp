class Solution {
public:
int r(vector<int>& nums) {
       int n=nums.size();
        if(n==1)return nums[0];
      int prev= nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){

    long long int pick=nums[i];
    if(i>1)pick+=prev2;
    long long int notpick= prev;
     int curri= max(pick,notpick);
     prev2=prev;
     prev=curri;
    }
    return prev;}

    int rob(vector<int>& arr) {
         int n=arr.size();
        if(n==1)return arr[0];
        vector<int>temp1(n);
        vector<int>temp2(n);
        for(int i=0;i<n;i++){
            if(i!=n-1)temp1.push_back(arr[i]);
            if(i!=0) temp2.push_back(arr[i]);
        }
      return max(r(temp2),r(temp1));
        
    }
};