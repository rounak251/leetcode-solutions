class Solution {
public:
long root_result=0;
vector<int>count;
int N;

int dfsbase(unordered_map<int,vector<int>>&adj,int u,int dist,int parent){
    root_result+=dist;
    int total_count=1;
    for(auto & it:adj[u]){
        if(it==parent)continue;
      total_count+=  dfsbase(adj,it,dist+1,u);
    }
count[u]=total_count;
return total_count;
}

void dfs(unordered_map<int,vector<int>>&adj,int u,int parent,vector<int>&result){
    for(int &child:adj[u]){
        if(child==parent)continue;
        result[child]=result[u]-count[child]+(N-count[child]);
        dfs(adj,child,u,result);
    }
}
 vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

 unordered_map<int,vector<int>>adj;
        for(auto &edge:edges){
            int u=edge[0];int v=edge[1];
            adj[u].push_back(v);adj[v].push_back(u);
        }
        N=n;
        count.resize(n,0);
        root_result=0;
        dfsbase(adj,0,0,-1);
        vector<int>result(n,0);
        result[0]=root_result;
        dfs(adj,0,-1,result);
        return result;
 }












// void dfs( unordered_map<int,vector<int>>&adj,int u,int parent,int dist,int &sum){
//     sum+=dist;
//     for(auto &node:adj[u]){
//         if(node==parent)continue;
//         dfs(adj,node,u,dist+1,sum);
//     }
// }
    // vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    //     unordered_map<int,vector<int>>adj;
    //     for(auto &edge:edges){
    //         int u=edge[0];int v=edge[1];
    //         adj[u].push_back(v);adj[v].push_back(u);
    //     }
    //     vector<int>result(n);


    //     for(int i=0;i<n;i++){
    //         queue<pair<int,pair<int,int>>>que;
    //         que.push({i,{-1,0}});
    //         int sum=0;
    //         while(!que.empty()){
    //             auto curr=que.front();
    //             que.pop();
    //             int node=curr.first;
    //             int dist=curr.second.second;
    //             int parent=curr.second.first;
    //             sum+=dist;
    //             for(auto &it:adj[node]){
    //                 if(parent==node) continue;
    //                 que.push({it,{node,dist+1}});
    //             }
    //         } result[i]=sum;

    //     } 
    //     // for(int i=0;i<n;i++){
    //     //     int sum=0;
    //     //     dfs(adj,i,-1,0,sum);
    //     //     result[i]=sum;
    //     // }
    //     return result;
    // }
};