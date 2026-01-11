class Solution {
public:
const int M=1e9+7;
int findpower(long long x,long long n){
    
    if(n==0) return 1;
    long long half=findpower(x,n/2);
    if(n%2==0) return (half*half)%M;
    else return (half*half*x)%M;
}
    int countGoodNumbers(long long n) {
       return ( (long long)findpower(5,(n+1)/2) *(long long) findpower(4,n/2))%M;
    }
};