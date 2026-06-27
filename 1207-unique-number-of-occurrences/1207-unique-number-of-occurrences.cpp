class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
   vector<int>a(2001,0);
   for(auto &it:arr){
    a[it+1000]++;
   }
   sort(a.begin(),a.end());
   for(int i=1;i<2001;i++){
    if(a[i]!=0    && a[i]==a[i-1])return false;
   }
        return true;
    }
};
// class Solution {
// public:
//     bool uniqueOccurrences(vector<int>& arr) {
//         unordered_map<int,int>hash;
//         for(int i=0;i<arr.size();i++){
//             hash[arr[i]]++;
//         }
//         unordered_set<int>st;
//         for(auto &it:hash){
//             int t=it.second;
//             if(st.find(t)!=st.end()) return false;
//             st.insert(t);
//         }
//         return true;
//     }
// };