class Solution {
public:
int dfs( unordered_map<int,vector<int>>&adj,int u,int parent,vector<bool>& hasApple){
    int time=0;
    for(auto &V:adj[u]){
        if(V==parent)continue;
        int time_of_child=dfs(adj,V,u,hasApple);
        if(time_of_child>0 || hasApple[V]==true){
            time+=time_of_child+2;
        }
    }return time;
}
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(adj,0,-1,hasApple);
    }
};