class Solution {
public:
    void dfs(unordered_map<int, vector<pair<int,int>>>& adj, int u,   vector<bool>& visited, int &minedge) {
        visited[u] = true;
        for (auto &[v, wt] : adj[u]) {
            minedge = min(minedge, wt);  
            if (!visited[v]) {
                dfs(adj, v, visited, minedge);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int,int>>> adj;

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int wt = road[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});  }
        vector<bool> visited(n + 1, false);
        int minedge = INT_MAX;
        dfs(adj, 1, visited, minedge);
        return minedge;
    }
};