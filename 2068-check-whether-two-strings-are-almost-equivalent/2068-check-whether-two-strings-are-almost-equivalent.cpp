class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int>hash1(26,0);
        vector<int>hash2(26,0);
        int n1=word1.size();
        int n2=word2.size();
        for(int i=0;i<n1;i++){
            hash1[word1[i]-'a']++;
        }
        for(int i=0;i<n2;i++){
            hash2[word2[i]-'a']++;
        }
      
        for(int i=0;i<26;i++){
  if(hash1[i]- hash2[i]>3 ||hash2[i]- hash1[i]>3)
return false;

        } return true;

    }
};