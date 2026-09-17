class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int n=arr.size();
        int i =0;int j=0;long long sum=0;int minlen =INT_MAX;
        while(i<n && j<n){
            sum+=arr[j];
            while(sum>=target){
                sum-=arr[i];
                int len=j-i+1;
                minlen=min(len,minlen);
                i++;
            }
           j++;
        }
        return (minlen == INT_MAX) ? 0 : minlen;
    }
};