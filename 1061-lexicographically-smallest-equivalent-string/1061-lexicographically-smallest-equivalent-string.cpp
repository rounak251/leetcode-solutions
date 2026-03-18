// class Solution {
// public:

// char dfs(unordered_map<char,vector<char>>&adj,char ch, vector<int>&visited){
//     visited[ch-'a']=1;
//     char mincha =ch;
//     for(auto &c:adj[ch]){
//    if(visited[c-'a']==0){
        
//        mincha=min(mincha, dfs(adj,c,visited));}
//     }
//     return mincha;
// }
//     string smallestEquivalentString(string s1, string s2, string baseStr) {
//         int n=s1.length();
//         int m=baseStr.length();
//         unordered_map<char,vector<char>>adj;
//         for(int i=0;i<n;i++){
//             char u=s1[i];char v=s2[i];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         string result;
//         for(int i=0;i<m;i++){
//             char ch=baseStr[i];
//             vector<int>visited(26,0);
//            char minchar= dfs(adj,ch,visited);
//             result.push_back(minchar);
//         }
//         return result;
//     }
// };
class Solution {
public:
    vector<int> parent;

    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int x, int y){
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        // attach bigger to smaller (important trick)
        if(px < py)
            parent[py] = px;
        else
            parent[px] = py;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {

        parent.resize(26);

        // initialize
        for(int i = 0; i < 26; i++)
            parent[i] = i;

        int n = s1.length();

        // union all pairs
        for(int i = 0; i < n; i++){
            unite(s1[i] - 'a', s2[i] - 'a');
        }

        string result;

        // build answer
        for(char ch : baseStr){
            int p = find(ch - 'a');
            result.push_back(p + 'a');
        }

        return result;
    }
};