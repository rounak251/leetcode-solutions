class Solution {
public:
    int titleToNumber(string col) {
        int n=col.size();int cnt=0;
        for(int i=n-1;i>=0;i--){
            cnt+=pow(26,n-i-1)*(col[i]-'A'+1);
        }
        return cnt;
    }
};