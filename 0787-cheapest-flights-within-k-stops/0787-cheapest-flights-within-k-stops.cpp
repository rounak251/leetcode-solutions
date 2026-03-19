

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);
        for(auto &edge : flights){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // {cost, node, stops}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, src, 0});

        vector<int> stops(n, INT_MAX);

        while(!pq.empty()){
            auto [cost, node, step] = pq.top();
            pq.pop();

            if(node == dst) return cost;

            if(step > k || step > stops[node]) continue;

            stops[node] = step;

            for(auto &it : adj[node]){
                int neigh = it.first;
                int wt = it.second;

                pq.push({cost + wt, neigh, step + 1});
            }
        }

        return -1;
    }
};
// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<int>dist(n,INT_MAX);
//         unordered_map<int,vector<pair<int,int>>>adj;
//         for(auto &edge:flights){
//             int u=edge[0];int v=edge[1];int wt=edge[2];
//             adj[u].push_back({v,wt});
//         }
//         queue<pair<int,int>>que;
//         que.push({src,0});
//         dist[src]=0;
//         int steps=0;
//         while(!que.empty() && steps<=k){
//             int N=que.size();
//             while(N--){
//                 auto curr=que.front();
//                 que.pop();
//                 int node=curr.first;
//                 int cost=curr.second;
//                 for(auto &u:adj[node]){
//                     int wt=u.second;
//                     int neighnode=u.first;

//                 if(cost+wt<dist[neighnode]){
//                 dist[neighnode]=cost+wt;que.push({neighnode,cost+wt});}
//                 }
//             } steps++;
//         }
//         if(dist[dst]==INT_MAX)return -1;
//         return dist[dst];
//     }
// };