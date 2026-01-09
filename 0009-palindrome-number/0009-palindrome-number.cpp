class Solution {
public:
    bool isPalindrome(int x) {
long long int original=x;
long long int reversed=0;
while(x>0){
   long long int t=x%10;
    x=x/10;
    reversed=reversed*10+t;
}if(original==reversed)return true;
else return false;
    }
};