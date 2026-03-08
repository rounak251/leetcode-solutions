class Solution {
public:

bool biparbfs(vector<vector<int>>& adj,int currnode, vector<int>&color,int currcolor){
    color[currnode]=currcolor;
    queue<int>que;
    que.push(currnode);
    while(!que.empty()){
        int node=que.front();que.pop();
        for(auto &v:adj[node]){
            if(color[v]==color[node])return false;
            if(color[v]==-1){
                color[v]=1-color[node];
                que.push(v);
            }
        }
    }return true;}

    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
              if(  biparbfs(adj,i,color,1)==false )return false;
            }
        }
        return true;
    }
};