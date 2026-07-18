class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int n =s.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(s[i]==y){
                swap(s[i],s[j]);j++;
            }
            
        }
        return s;
        
    }
};