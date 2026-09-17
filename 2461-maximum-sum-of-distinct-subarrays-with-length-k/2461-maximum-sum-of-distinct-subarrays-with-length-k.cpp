class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>hash;
        long long maxsum=0;
        long long sum=0;
        for(int i=0;i<k;i++){
            hash[arr[i]]++;
                sum+=arr[i];
                if(hash.size()==k)maxsum=sum;
        }
        for(int i=k;i<n;i++){
            hash[arr[i]]++;
            sum+=arr[i];
            hash[arr[i-k]]--;
            sum-=arr[i-k];
            if(hash[arr[i-k]]==0)hash.erase(arr[i-k]);
            if(hash.size()==k )maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
};