class Solution {
public:
bool checkdfs(unordered_map<int,vector<int>>&mp,int u,vector<int>&color){
   
    for(auto &v:mp[u]){
        
        if(color[v]==-1){
            color[v]=1-color[u];
            
            if(checkdfs(mp,v,color)==false)
                return false;
        }
        
        else if(color[v]==color[u])
            return false;
    }
    
    return true;
}

 bool checkbfs(unordered_map<int,vector<int>>&mp,int u,vector<int>&color){
    queue<int>que;
    que.push(u);
    color[u]=1;
    while(!que.empty()){
        int node=que.front();que.pop();
        for(auto &it:mp[node]){
            if(color[it]==color[node])return false;
            if(color[it]==-1){
                que.push(it);color[it]=1-color[node];
            }
        }
    } return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>mp;
        for(auto &edge:dislikes){
           int u= edge[0];
           int v= edge[1];
           mp[u].push_back(v);
           mp[v].push_back(u);
        }
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1)
            {
                if(checkdfs(mp,i,color)==false)return false;
            }
        }
        return true;
    }
};