
class Solution {
public:
typedef pair<double,int>P;
   
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

        unordered_map<int,vector<pair<int,double>>> adj(n);

    
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

       vector<double>result(n,0);
       priority_queue<P>pq;//maxheap
       result[start]=1.0;
       pq.push({1.0,start});
       while(!pq.empty()){
        auto v=pq.top();pq.pop();
        double prob=v.first;
        int node=v.second;
          for(auto &x:adj[node]){
            double prog=x.second;
            int nodex=x.first;
            if(prog*prob > result[nodex]){
                result[nodex]=prog*prob;
                pq.push({prog*prob,nodex});
            }
          }
       }
       return result[end];
    }
};

// class Solution {
// public:
//     void dfs(int u, int end,
//              vector<vector<pair<int,double>>>& adj,
//              vector<bool>& visited,
//              double prob,
//              double &maxProb) {
        
//         // If we reach destination
//         if(u == end){
//             maxProb = max(maxProb, prob);
//             return;
//         }

//         visited[u] = true;

//         for(auto &p : adj[u]){
//             int v = p.first;
//             double edgeProb = p.second;

//             if(!visited[v]){
//                 dfs(v, end, adj, visited, prob * edgeProb, maxProb);
//             }
//         }

//         visited[u] = false; // 🔥 backtrack
//     }

//     double maxProbability(int n, vector<vector<int>>& edges,
//                           vector<double>& succProb,
//                           int start, int end) {

//         unordered_map<int,vector<pair<int,double>>> adj(n);

    
//         for(int i = 0; i < edges.size(); i++){
//             int u = edges[i][0];
//             int v = edges[i][1];
//             double p = succProb[i];

//             adj[u].push_back({v, p});
//             adj[v].push_back({u, p});
//         }

//         vector<bool> visited(n, false);
//         double maxProb = 0.0;

//         dfs(start, end, adj, visited, 1.0, maxProb);

//         return maxProb;
//     }
// };