#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent, rank;

    int findparent(int x) {
        if (x == parent[x]) return x;
        return parent[x] = findparent(parent[x]);
    }

    void unite(int x, int y) {
        int px = findparent(x);
        int py = findparent(y);
        if (px == py) return;

        if (rank[px] > rank[py]) parent[py] = px;
        else if (rank[py] > rank[px]) parent[px] = py;
        else {
            parent[px] = py;
            rank[py]++;
        }
    }

    int krushkal(vector<vector<int>>& edges, int skip, int add, int n) {
        // RESET DSU every time
        parent.resize(n);
        rank.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;

        int sum = 0;
        int edges_used = 0;

        // Force include an edge
        if (add != -1) {
            unite(edges[add][0], edges[add][1]);
            sum += edges[add][2];
            edges_used++;
        }

        for (int i = 0; i < edges.size(); i++) {
            if (i == skip) continue;

            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            if (findparent(u) != findparent(v)) {
                unite(u, v);   // ✅ FIXED
                sum += wt;
                edges_used++;
            }
        }

        // If not a valid MST
        if (edges_used != n - 1) return INT_MAX;

        return sum;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        // add index to edges
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }

        // sort by weight
        sort(edges.begin(), edges.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[2] < b[2];
             });

        int mst_weight = krushkal(edges, -1, -1, n);

        vector<int> critical, pseudo;

        for (int i = 0; i < edges.size(); i++) {
            // If skipping increases weight → critical
            if (krushkal(edges, i, -1, n) > mst_weight) {
                critical.push_back(edges[i][3]);
            }
            // If forcing keeps same weight → pseudo-critical
            else if (krushkal(edges, -1, i, n) == mst_weight) {
                pseudo.push_back(edges[i][3]);
            }
        }

        return {critical, pseudo};
    }
};