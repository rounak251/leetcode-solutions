class Solution {
public:

// bool checkdfs( unordered_map<int,vector<int>>&mp,int s,int d,vector<bool>&visited){
//     if(s==d)return true;
//     if(visited[s]==true)return false;
//     visited[s]=true;
//     for(auto &it:mp[s]){
//         if(check(mp,it,d,visited)==true)return true;
//     }
//     return false;
// }
  bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination)return true;
        unordered_map<int,vector<int>>mp;
        vector<bool>visited(n,false);
        for(auto &edge:edges){
            int u=edge[0];int v=edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        queue<int>que;
        que.push(source);
        visited[source]=true;
        while(!que.empty()){
            int node=que.front();
            que.pop(); if(node==destination) return true;
            for(auto &it:mp[node]){
               
               if(visited[it] !=true){que.push(it);
                visited[it]=true;}
            }
        }
        return false;
        //return checkdfs(mp,source,destination,visited);
    }
};