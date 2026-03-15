class Solution {
public:
void dfs(vector<vector<int>>& graph, int u,int dist,   vector<vector<int>>&result, vector<int>&temp){
    temp.push_back(u);
    if(u==dist) result.push_back(temp);
    else{
        for(auto &it:graph[u]){
            dfs(graph,it,dist,result,temp);
        }

    }
    temp.pop_back();
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>result;
        int n=graph.size();
        int src=0;int dist=n-1;
        vector<int>temp;
        dfs(graph,src,dist,result,temp);
        return result;
    }
};