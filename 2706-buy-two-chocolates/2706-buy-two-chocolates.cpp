class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int sum=0;int cnt=0;
        sort(prices.begin(),prices.end());
        for(int i=0;i<prices.size();i++){
            sum+=prices[i]; cnt++;
            if(cnt==2){
            if (sum <= money) 
                    return money - sum;  // return remaining money
                else 
                    return money; 
            }
           
        }
        return money;}
    
};