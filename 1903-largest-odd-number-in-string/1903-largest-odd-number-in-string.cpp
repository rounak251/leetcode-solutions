class Solution {
public:
    string largestOddNumber(string num) {
        // int number=stoi(num);
        // if(number%2!=0) return num;
        int n=num.size();
        // for(int i=0;i<num.size();i++){
        //     if(stoi(num[i])%2!=0) return num[i];
        // }
        for(int i=n-1;i>=0;i--){
        if((num[i]-'0')%2!=0) return num.substr(0,i+1);
        }
        return "";
    }
};