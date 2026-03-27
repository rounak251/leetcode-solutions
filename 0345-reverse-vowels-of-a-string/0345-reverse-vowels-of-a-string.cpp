class Solution {
public:
bool isvowel(char &c){
if(c =='A'|| c =='a'|| c =='i'|| c =='I'|| c =='e'

||c =='E'|| c =='O'||c =='o' || c=='U'||c=='u')return true;
return false;
        
        }
    string reverseVowels(string s) {
        int n=s.length();
        int i=0;int j=n-1;
        while(i<=j){
         if(!isvowel(s[i]))i++;
         else if (!isvowel(s[j]))j--;
         else{
            swap(s[i],s[j]);i++;j--;
         }
         } return s;
    }
};