class Solution {
public:
    int countGoodSubstrings(string s) {
        int l=0 ;int r=0;int n=s.size();int cnt=0;      
              vector<int> hash(26,0);
        while(r<n){

            hash[s[r]-'a']++;
            if(r-l+1==3){
 if(hash[s[l]-'a']==1&& hash[s[l+1]-'a']==1&& hash[s[l+2]-'a']==1)cnt++;
                 hash[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return cnt;
    }
};