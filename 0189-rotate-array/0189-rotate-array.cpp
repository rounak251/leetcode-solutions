class Solution {
public:
void reverse(int index,int x,vector<int>& arr){
    for(int i=index;i<x/2;i++){
        swap(arr[i],arr[x-i-1]);
    }
}
    void rotate(vector<int>& arr, int k) {
        int n=arr.size();
        k=k%n;
        reverse(0,n,arr);
        reverse(0,k,arr);
        reverse(k,n+k,arr);

    }
};