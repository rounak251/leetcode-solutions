class Solution {
public:
int n;
void bfs(vector<vector<int>>& adj,int u,vector<bool>&visited){
    queue<int>que;
    visited[u]=true;
    que.push(u);
    while(!que.empty()){
        int node=que.front();que.pop();
        for(int v=0;v<n;v++){
            if(!visited[v] && adj[node][v]==1){
                visited[v]=true;que.push(v);
            }
        }
    }
}
void dfs( unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited){
        visited[u]=true;
        for(auto &v:adj[u]){
            if(!visited[v]) dfs(adj,v,visited);}
    }
    int findCircleNum(vector<vector<int>>& adj) {
        n=adj.size();
        // unordered_map<int,vector<int>>adj;
        // //adjancency list 
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(isConnected[i][j]==1){
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);

        //         }
        //     }
        // }
        int count=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
           
                if(!visited[i])
                  { bfs(adj,i,visited);
                count++;}
          
        }return count;
    }
};