class Solution {
public:
    int addDigits(int num) {
       long long int s1=num;

        while(s1>0){
     long long int s2=s1%10;
     s1/=10;
     s1=s1+s2;
     if(s1<10) break;
        }return s1;
    }
};