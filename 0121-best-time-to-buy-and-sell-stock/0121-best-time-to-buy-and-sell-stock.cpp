class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n =arr.size();
        int maxprofit =0;
        int minbuy=INT_MAX;
        for(int i=0;i<n;i++){
            minbuy=min(minbuy,arr[i]);
                 maxprofit=max(maxprofit,arr[i]-minbuy);
        }
        return maxprofit;}
    
};