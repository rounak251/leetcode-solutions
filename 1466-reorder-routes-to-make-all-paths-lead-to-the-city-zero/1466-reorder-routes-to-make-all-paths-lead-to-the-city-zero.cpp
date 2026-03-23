class Solution {
public:
int count =0;
void dfs(int u,int parent,unordered_map<int,vector<pair<int,int>>>&adj){
    for(auto &[v,check]:adj[u]){
        if(v!=parent){
            if(check==1)count++;
              dfs(v,u,adj); 
        }
    }
}
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &edge:connections){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});    }
            dfs(0,-1,adj);
            return count;
    }
};