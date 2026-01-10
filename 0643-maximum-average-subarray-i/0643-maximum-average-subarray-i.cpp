class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       
      double maxsum=0;
       int n=nums.size();
         double sum=0;
        for(int i=0;i<k;i++){
            sum=sum + nums[i];}
                maxsum=sum;
            
             for(int i = k; i < n; i++){
            sum += nums[i];       
            sum -= nums[i - k];  
            maxsum = max(maxsum, sum);
        }
        
        double average=maxsum/k;
        return average;
    }
};