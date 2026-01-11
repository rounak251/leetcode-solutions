class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int n=arr.size();
        int low=0;int high=n-1;
        vector<int>ans(2,-1);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                int first=mid,last=mid;
       while(first>0 && arr[first-1]==target)first--;
     while(last<n-1 && arr[last+1]==target )last++;
              ans[0]=first;
              ans[1]=last;
           return ans;
            }
            else if (arr[mid]<target )low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
};