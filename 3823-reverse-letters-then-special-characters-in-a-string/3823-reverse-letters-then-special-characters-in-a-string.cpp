class Solution {
public:
    string reverseByType(string s) {
        vector<char>a,b;
        string ans="";
        for(char c:s){
            if(isalpha(c))a.push_back(c);
            else b.push_back(c);
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0;int j=0;
        for(char c:s){
            if(isalpha(c))ans+=a[i++];
            else ans+=b[j++];
        }
        return ans;
    }
};