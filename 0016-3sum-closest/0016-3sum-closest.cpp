class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int mindiff=INT_MAX;
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){

            int l=i+1;int r=n-1;
            while(l<r){
                long long sum=nums[i]+nums[l]+nums[r];
                if(sum==target) return sum;
                long long diff=abs((long long )target-sum);
                if(diff<mindiff){
                    mindiff=diff;
                    ans=sum;

                }
                 if(sum<target) l++;
                else r--;

            }
        }
        return ans;
    }
};