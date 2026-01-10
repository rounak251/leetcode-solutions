class Solution {
public:
    int minimumDifference(vector<int>& arr, int k) {
        int n=arr.size();
        if(n==0 || n==1)return 0;
        sort(arr.begin(),arr.end());
        int l=0;int r=0;int mindiff=INT_MAX;
        while(r<n){
            if(r-l+1==k){
        mindiff=min(mindiff,arr[r]-arr[l]);
                l++;
            }r++;
        }
        return mindiff;
    }
};