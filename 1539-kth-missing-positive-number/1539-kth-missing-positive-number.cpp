class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int maxVal = 0;
        for (int num : arr) maxVal = max(maxVal, num);

        // hash array size = max number in arr + k (to be safe)
        int size = maxVal + k +1;
        vector<int> hash(size, 0);

        for(int i=0;i<arr.size();i++){
            hash[arr[i]]++;
        }int cnt=0;int x=0;
        for(int i=1;i<size;i++){
       if(hash[i]==0)cnt++;
       if(cnt==k) {x=i;break;} 
        }
        return x;
    }
};