class Solution {
public:
    int reverse(int x) {
      long long  int n=x;long long int z=0;
        if(x<0) n=-n;
        
        while(n>0){
            int a =n%10;
            n=n/10;
             z=z*10+a;
        } if (z > INT_MAX) return 0; 
        if(x<0) return -1*z;
        else return z;
        
    }
};