class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        int n=s.size();
        unordered_map<char,int>maps;
        int l=0;int r=0;int maxlen=0;
        while(r<n){
            maps[s[r]]++;
            
            while(maps[s[r]]>1){
                maps[s[l]]--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);r++;
        }
return maxlen;}
    //     int n= s.size();
    //     int len=0;
    //     int maxlen=0;
    //     vector<int> hash(256,-1);
    //     int l=0;int r=0;
    //     while(r<n){
    //         if(hash[s[r]]!=-1){
    //             if(hash[s[r]]>=l) l=hash[s[r]]+1;

    //         }
    //         len=r-l+1;
    //         maxlen =max(maxlen,len);
    //         hash[s[r]]=r;
    //         r++;

    //     }
        

            
        
    //     return maxlen;
    // }
};