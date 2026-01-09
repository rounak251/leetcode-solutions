class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
       int i=0;
          if(arr.empty()) return 0;
       int n=arr.size();
       for(int j=0;j<n;j++){
        if(arr[j]!=arr[i]){ i++;
        arr[i]=arr[j];
       }}
        return i+1;
    }
};