class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& arr) {
        int n=arr.size();
        int c=INT_MAX;
        for(int i=0;i<n;i++){
         c=min(c,arr[i]);
        }
        int a=INT_MIN;int b=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>a){
               
                b=a; a=arr[i];
            }
            else if(arr[i]>b) b=arr[i];
        }
        return (a+b-c);
    }
};