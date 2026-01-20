class Solution {
public:
long long func(vector<int>& arr,int n,int k){
    long long total=0;
    for(int i=0;i<n;i++){
        total+=(arr[i]+k-1)/k;
    }return total;
}int maxele(vector<int>& arr,int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(max<arr[i]) max=arr[i];
    }return max;
}
    int smallestDivisor(vector<int>& arr, int threshold) {
        int n=arr.size();
        int low=1;int high=maxele(arr,n);
        while(low<=high){
            int mid=low+(high-low)/2;
            long long totalh=func(arr,n,mid);
            if(totalh<=threshold) high=mid-1;
            else low=mid+1;
        } return low;
    }
};