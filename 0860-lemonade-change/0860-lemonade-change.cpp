class Solution {
public:
    bool lemonadeChange(vector<int>& arr) {
        int five=0;int ten=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==5){
                five++;
            }
            else if(arr[i]==10){
                if(five){five--;ten++;}
                else return false;
            }
            else{
                if(five && ten){
                    five--;ten--;
                }
               else if(five>=3) five-=3;
                 else return false;
            }
        }
        return true;
    }
};