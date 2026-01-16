class Solution {
public:
vector<string>ans;
// bool isvalid(string &s){
//     int count=0;
//     for(int i=0;i<s.size();i++){
//     if(s[i]=='(') count++;
//     else count--
//     ;if (count < 0) return false;}
//     return count==0;
// }
void solve(string &s,int n,int open,int close){
    if(s.size()==2*n){
       // if(isvalid(s)) 
       ans.push_back(s);
        return;
    }if(open<n){
    s.push_back('(');
    solve(s,n,open+1,close);
    s.pop_back();}
    if(close<open){
    s.push_back(')');
    solve(s,n,open,close+1);
    s.pop_back();}
}
    vector<string> generateParenthesis(int n) {
        string s="";
        int open=0;
        int close=0;
        solve(s,n,open,close);
        return ans;
    }
};