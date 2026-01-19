class Solution {
public:
    int mySqrt(int x) {
       long int low=0;long long int high=x;
        while(low<=high){
          long long int  mid=low+(high-low)/2;
            if(mid*mid==x)return mid;
            else if(mid*mid>x)high=mid-1;
            else low=mid+1;
        }
        return high;
    }
};