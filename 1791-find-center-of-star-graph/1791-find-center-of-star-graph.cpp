class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
       // int n=edges.size();
       vector<int>first=edges[0];
       vector<int>second=edges[1];
       if(first[0]==second[0]||first[0]==second[1])return first[0];
       return first[1];
        
    }
};
// unordered_map<int,int>degree;
//         for(auto &in :edges){
//             int u=in[0];
//             int v=in[1];
//             degree[u]++;
//             degree[v]++;

//         }
//         for(auto &it:degree){
//             if(it.second==edges.size())
//             return it.first;
//         }return -1;