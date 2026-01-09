class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
          if(s[i]=='I') ans+=1;
          if(s[i]=='V') ans+=5;
          if(s[i]=='X') ans+=10;
          if(s[i]=='L') ans+=50;
          if(s[i]=='C') ans+=100;
          if(s[i]=='D') ans+=500;
          if(s[i]=='M') ans+=1000;
        if (i > 0) {
                if (s[i-1] == 'I' && (s[i] == 'V' || s[i] == 'X')) ans -= 2;
                if (s[i-1] == 'X' && (s[i] == 'L' || s[i] == 'C')) ans -= 20;
                if (s[i-1] == 'C' && (s[i] == 'D' || s[i] == 'M')) ans -= 200;
            }}
        return ans;
    }
};