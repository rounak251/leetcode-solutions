class Solution {
public:

    void dfs(vector<int>& edges, int node, vector<long long>& dist, vector<bool>& visited){
        visited[node] = true;
        int v = edges[node];

        if(v != -1 && !visited[v]){
            dist[v] = dist[node] + 1;
            dfs(edges, v, dist, visited);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<long long> dist1(n, INT_MAX);
        vector<long long> dist2(n, INT_MAX);
        vector<bool> visited1(n, false);
        vector<bool> visited2(n, false);

        dist1[node1] = 0;
        dist2[node2] = 0;

        dfs(edges, node1, dist1, visited1);
        dfs(edges, node2, dist2, visited2);

        int minnode = -1;
        long long mindist = LLONG_MAX;

        for(int i = 0; i < n; i++){
            if(dist1[i] == INT_MAX || dist2[i] == INT_MAX) continue;

            long long maxd = max(dist1[i], dist2[i]);

            if(mindist > maxd){
                mindist = maxd;
                minnode = i;
            }
        }

        return minnode;
    }
};