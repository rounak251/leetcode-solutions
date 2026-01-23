class Solution {
public:
void merge(int l,int mid,int h,vector<int>&arr){
    vector<int>temp;
    int left=l;int right=mid+1;
    while(left<=mid&&right<=h) {
       if (arr[left] <= arr[right])temp.push_back(arr[left++]);
        else temp.push_back(arr[right++]);
    }
    while(left<=mid)temp.push_back(arr[left++]);
    while(right<=h)temp.push_back(arr[right++]);
    for(int i=l;i<=h;i++){
        arr[i]=temp[i-l];
    }
}

void mergesort(int l,int h,vector<int>&arr){
    if(l>=h)return;
        int mid=l+(h-l)/2;
        mergesort(l,mid,arr);
        mergesort(mid+1,h,arr);
        merge(l,mid,h,arr);
    
}
    vector<int> sortArray(vector<int>& arr) {
        int n=arr.size();
        mergesort(0,n-1,arr);
        return arr;
    }
};