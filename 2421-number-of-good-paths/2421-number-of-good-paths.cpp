class Solution {
public:
    vector<int> parent, rank;

    int findparent(int x){
        if(x == parent[x]) return x;
        return parent[x] = findparent(parent[x]);
    }

    void unite(int x, int y){
        int x_ = findparent(x);
        int y_ = findparent(y);
        if(x_ == y_) return;

        if(rank[x_] > rank[y_]) parent[y_] = x_;
        else if(rank[y_] > rank[x_]) parent[x_] = y_;
        else {
            parent[y_] = x_;
            rank[x_]++;
        }
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();

        parent.resize(n);
        rank.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;

        unordered_map<int, vector<int>> adj;
        for(auto &edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // value -> nodes
        unordered_map<int, vector<int>> val_tonodes;
        for(int i = 0; i < n; i++){
            val_tonodes[vals[i]].push_back(i);
        }

        // sort unique values
        vector<int> unique_vals;
        for(auto &it : val_tonodes){
            unique_vals.push_back(it.first);
        }
        sort(unique_vals.begin(), unique_vals.end());

        int result = n;
        vector<bool> is_active(n, false);

        for(int val : unique_vals){
            vector<int> &nodes = val_tonodes[val];

            // activate and union
            for(int &u : nodes){
                for(int &v : adj[u]){
                    if(is_active[v]){
                        unite(u, v);
                    }
                }
                is_active[u] = true;
            }

            // count components
            map<int, int> count;
            for(int &u : nodes){
                int p = findparent(u);
                count[p]++;
            }

            for(auto &it : count){
                int c = it.second;
                result += (c * (c - 1)) / 2;
            }
        }

        return result;
    }
};