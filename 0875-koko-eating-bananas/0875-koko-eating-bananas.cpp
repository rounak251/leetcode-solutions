class Solution {
public:

long long fuc(vector<int>& arr, int k){
    long long  totaltime=0;
    for(int i=0;i<arr.size();i++){
        totaltime+=(arr[i] + k - 1) / k;
    }return totaltime;
}
int maxele(vector<int>& arr,int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(max<arr[i]) max=arr[i];
    }return max;
}
    int minEatingSpeed(vector<int>& arr, int h) {
        int n=arr.size();
        int low=1;int high=maxele(arr,n);//int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
         long long  totalh=fuc(arr,mid);
         if(totalh<=h){ high=mid-1;}
         else{low=mid+1;}
        }return low;}
    
};