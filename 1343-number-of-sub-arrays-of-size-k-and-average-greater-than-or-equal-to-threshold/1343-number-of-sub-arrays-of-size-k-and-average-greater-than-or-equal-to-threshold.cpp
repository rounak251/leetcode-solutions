class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt=0;
        int l=0;int r=0;
        int n=arr.size();
           int sum =0;
        while(r<n){
         sum+=arr[r];
           if(r-l+1==k){
         int avg=sum/k;
            if(avg >=threshold)
            cnt++;
            sum-=arr[l];
            l++;
           }
           r++;
        }return cnt;
            
       
    }
};