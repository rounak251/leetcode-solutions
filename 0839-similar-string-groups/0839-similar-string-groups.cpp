class Solution {
public:
bool issimilar(string &s1,string &s2){
int n=s1.size();
int diff=0;
for(int i=0;i<n;i++){
    if(s1[i]!=s2[i])diff++;

}

return diff==2 || diff==0;

}
void dfs(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited){
    visited[u]=true;
    for(auto &v:adj[u]){
        if(!visited[v])
        dfs(adj,v,visited);
    }
}
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
            if(issimilar(strs[i],strs[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
}

            }
        }

        vector<bool>visited(n,false);
        int count =0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,i,visited);
                count++;
            }
        }
        return count;
    }
};