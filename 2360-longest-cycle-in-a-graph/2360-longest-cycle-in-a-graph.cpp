class Solution {
public:
int result=-1;

void dfs(vector<int>& edges,int u, vector<bool>&visited,vector<bool>&inrecurr, vector<int>&count){
    if(u!=-1){
    visited[u]=true;
    inrecurr[u]=true;
    int v=edges[u];
   
    if(v!=-1 && !visited[v] ){count[v]=count[u]+1;
    dfs(edges,v,visited,inrecurr,count); }
    else if( v!=-1 && inrecurr[v]==true) {
   result=max(result,count[u]-count[v]+1);
    }
    inrecurr[u]=false;
}}
    int longestCycle(vector<int>& edges) {
       int n=edges.size();
       vector<bool>visited(n,false);
       vector<bool>inrecurr(n,false);
       vector<int>count(n,1);
       for(int i=0;i<n;i++){
        if(!visited[i])
        dfs(edges,i,visited,inrecurr,count);
       }
       return result;
    }
};