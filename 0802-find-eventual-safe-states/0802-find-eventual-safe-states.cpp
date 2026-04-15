class Solution {
public:

bool iscycledfs(int u,vector<vector<int>>& adj, vector<bool>&visited,vector<bool>&inrecurr){
    visited[u]=true;
    inrecurr[u]=true;
    for(auto &v:adj[u]){
        if(!visited[v] && iscycledfs(v,adj,visited,inrecurr)) return true;
        else if(inrecurr[v]) return true;

    }
    inrecurr[u]=false;
    return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        // unordered_map<int,vector<int>>adj;
        // int N=graph.size();
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<graph[i].size();j++){
        //       adj[i].push_back(graph[i][j]);
        // }}
        int N=adj.size();
        vector<bool>visited(N,false);
        vector<bool>inrecurr(N,false);
        vector<int>safenodes;
        for(int i=0;i<N;i++){
            if(!visited[i] )
            { 
                iscycledfs(i,adj,visited,inrecurr);}
        }
        for(int i=0;i<N;i++){
            if(inrecurr[i]==false) safenodes.push_back(i);
        }
        return safenodes;
    }
};