class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> hash(52, 0);

        for (char c : s) {
            if (c >= 'a' && c <= 'z')
                hash[c - 'a']++;
            else
                hash[c - 'A' + 26]++;
        }int result=0;bool oddfound=false; 
        for(int i=0;i<52;i++){
        if( hash[i]%2==0)result+=hash[i];
           else{result += hash[i] - 1;
                oddfound = true;
           }

        }if(oddfound)result++;
        return result;
    }
};