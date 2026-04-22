#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

vector<int> toposort(vector<vector<int>>& adj, vector<int>& indegree) {
    queue<int> q;
    int n = indegree.size();

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> res;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        res.push_back(u);

        for(int v : adj[u]) {
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    }

    return res.size() == n ? res : vector<int>();
}

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

    // Assign unique group to -1 items
    for(int i = 0; i < n; i++) {
        if(group[i] == -1) group[i] = m++;
    }

    // Item graph
    vector<vector<int>> itemGraph(n);
    vector<int> itemIndegree(n, 0);

    // Group graph
    vector<vector<int>> groupGraph(m);
    vector<int> groupIndegree(m, 0);

    // Build graphs
    for(int i = 0; i < n; i++) {
        for(int prev : beforeItems[i]) {

            // item dependency
            itemGraph[prev].push_back(i);
            itemIndegree[i]++;

            // group dependency
            if(group[i] != group[prev]) {
                groupGraph[group[prev]].push_back(group[i]);
                groupIndegree[group[i]]++;
            }
        }
    }

    // Topological sorts
    vector<int> itemOrder = toposort(itemGraph, itemIndegree);
    vector<int> groupOrder = toposort(groupGraph, groupIndegree);

    if(itemOrder.empty() || groupOrder.empty()) return {};

    // Map group → items
    unordered_map<int, vector<int>> groupToItems;

    for(int item : itemOrder) {
        groupToItems[group[item]].push_back(item);
    }

    // Build final result
    vector<int> result;

    for(int g : groupOrder) {
        for(int item : groupToItems[g]) {
            result.push_back(item);
        }
    }

    return result;
}
};