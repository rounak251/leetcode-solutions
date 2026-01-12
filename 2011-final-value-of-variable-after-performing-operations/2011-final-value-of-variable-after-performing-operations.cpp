class Solution {
public:
    int finalValueAfterOperations(vector<string>& s) {
        int X=0;
        for(int i =0;i<s.size();i++){
 if(s[i]=="++X") X+=1;
 if(s[i]=="X++")X+=1;
  if(s[i]=="--X")X-=1;
  if(s[i]=="X--")X-=1;
        }return X;
       
    }
};