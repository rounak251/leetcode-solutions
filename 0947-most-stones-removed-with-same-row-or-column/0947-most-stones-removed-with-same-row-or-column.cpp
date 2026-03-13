class Solution {
public:
    void dfs(vector<vector<int>>& stones, int index, vector<bool>& visited){
        visited[index] = true;
        for(int i = 0; i < stones.size(); i++){
            int r = stones[index][0];
            int c = stones[index][1];
            if(!visited[i] && (stones[i][0] == r || stones[i][1] == c)){
                dfs(stones, i, visited);
            } }}

vector<int>parent,rank;
int find(int x){
    if(x==parent[x])return parent[x];
    return parent[x]=find(parent[x]);
}
void Union(int x,int y){
    int x_parent=find(x);
    int y_parent=find(y);
    if(x_parent==y_parent) return;
    if(rank[x_parent]>rank[y_parent]){
        parent[y_parent]=x_parent;
    }
    else if(rank[x_parent]<rank[y_parent]) 
    parent[x_parent]=y_parent;
    else{
        parent[x_parent]=y_parent;
        rank[y_parent]++;
    }
}

    int removeStones(vector<vector<int>>& stones) {
int n=stones.size();
parent.resize(n);
rank.resize(n,0);
for(int i=0;i<n;i++){
    parent[i]=i;
}
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1]) Union(i,j);
    }
}
int components=0;
for(int i=0;i<n;i++){
    if(find(i)==i)components++;
}
return n-components;




    }
//         int n = stones.size();
//         vector<bool> visited(n, false);
//         int group = 0;

//         for(int i = 0; i < n; i++){
//             if(visited[i]) continue;
//             dfs(stones, i, visited);
//             group++;
// }   return n - group; }
};