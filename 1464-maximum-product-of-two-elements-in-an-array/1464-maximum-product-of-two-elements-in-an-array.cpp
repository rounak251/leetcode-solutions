class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n=arr.size();
        int firstMax=0;int secondMax=0;
        for(int i=0;i<n;i++){
             if (arr[i] > firstMax) {
                secondMax = firstMax;
                firstMax = arr[i];
            } 
            else if (arr[i] > secondMax) {
                secondMax = arr[i];
            }}
        
        return (firstMax-1)*(secondMax-1);
    }
};