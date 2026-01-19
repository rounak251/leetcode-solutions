class Solution {
public:
    string convertToTitle(int colnum) {
        string s="";
       while(colnum>0){
colnum--;
        s=char((colnum%26)+'A')+s;
        colnum/=26;

        }
        return s;
    }
};