class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>hash(26,0);
        int result=0;
        for(auto &ch:chars){
            hash[ch-'a']++;
        }
        for(auto &word:words){
             vector<int>hashword(26,0);
            for(auto &wo:word){
hashword[wo-'a']++;
            }
            bool ok=true;
            for(int i=0;i<26;i++){
                if(hashword[i]>hash[i]){
                    ok=false;
                    break;
                }
            }
            if(ok==true) result+=word.length();
        }
return result;
    }
};