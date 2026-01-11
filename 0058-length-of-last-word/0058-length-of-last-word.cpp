class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int cnt=0;int x=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==' ' && x==0) continue;
          else  if(s[i]==' ') {
                break;
            };
            x++;
        }
        return x;
    }
};