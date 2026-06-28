class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<vector<long long>> dist(n, vector<long long>(power + 1, LLONG_MAX));
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> pq;

        pq.push({0, source, power});
        dist[source][power] = 0;
        long long bestTime = -1;
        int bestPower = -1;

        while (!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            long long time = cur[0];
            int node = cur[1];
            int rem = cur[2];
            
             if (time > dist[node][rem])
                continue;

            if (bestTime != -1 && time > bestTime)
                break;

            if (node == target) {
                if (bestTime == -1)
                    bestTime = time;

                if (time == bestTime)
                    bestPower = max(bestPower, rem);

                continue;
            }
            if (rem < cost[node])
                continue;
            int newPower = rem - cost[node];
            for (auto &it : adj[node]) {
                int nextNode = it.first;
                int edgeTime = it.second;
                long long newTime = time + edgeTime;
                if (newTime < dist[nextNode][newPower]) {
                    dist[nextNode][newPower] = newTime;
                    pq.push({ newTime,nextNode,newPower});
                }}}
        
        if (bestTime == -1)
            return {-1, -1};

        return {bestTime, bestPower};

    }
    
};