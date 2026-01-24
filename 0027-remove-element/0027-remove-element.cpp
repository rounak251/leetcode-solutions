class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        vector<int>temp;int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]!=val)temp.push_back(arr[i]);
        }int m=temp.size();
        for(int i=0;i<m;i++){
            arr[i]=temp[i];
        }return m;
    }
};