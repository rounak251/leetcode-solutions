class Solution {
public:
//using kruhkal

  vector<int>parent;vector<int>rank;
  int findparent(int x){
      if(x==parent[x]) return x;
      return parent[x]=findparent(parent[x]);
  }
  void unite(int x,int y){
      int x_parent=findparent(x);
      int y_parent=findparent(y);
      if(x_parent==y_parent)return;
      if(rank[x_parent]>rank[y_parent]) parent[y_parent]=x_parent;
      else  if(rank[y_parent]>rank[x_parent]) parent[x_parent]=y_parent;
      else{
          parent[x_parent]=y_parent;
          rank[y_parent]++;
      }
  }
 int minCostConnectPoints(vector<vector<int>>& points) {
       int V=points.size();
       parent.resize(V);
rank.resize(V,1);
for(int i=0;i<V;i++){
    parent[i]=i;
}
       int sum=0;
       vector<vector<int>>edges;
       for(int i=0;i<V;i++){
        for(int j=i+1;j<V;j++){
            int wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
            edges.push_back({i,j,wt});
        }
       }
       auto cmp=[&](vector<int>&temp1,vector<int>&temp2){
    return temp1[2]<temp2[2];
};
sort(edges.begin(),edges.end(),cmp);
     
       for(auto &temp:edges){
        int u=temp[0];
        int v=temp[1];
        int wtt=temp[2];
        int u_parent=findparent(u);
        int v_parent=findparent(v);
        if(u_parent != v_parent) {
            unite(u_parent,v_parent);
            sum+=wtt;
        }
       }
       return sum;
 }
};
//using prims
//     int minCostConnectPoints(vector<vector<int>>& points) {
//        int V=points.size();
//        unordered_map<int,vector<pair<int,int>>>adj;
//        for(int i=0;i<V;i++){
//         for(int j=i+1;j<V;j++){
//             int x1=points[i][0];int x2=points[j][0];
//             int y1=points[i][1];int y2=points[j][1];
//             int dist=abs(abs(x2-x1)+abs(y2-y1));
//             adj[i].push_back({j,dist});
//             adj[j].push_back({i,dist});
//         }
//        }
//        vector<bool>visited(V,false);
//        int totalcost=0;
//        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
//        pq.push({0,0,-1});
//        while(!pq.empty()){
//         auto tt=pq.top();pq.pop();
//         int node=tt[1];
//         int wt=tt[0];
//         int parent=tt[2];
//         if(visited[node])continue;
//         visited[node]=true;totalcost+=wt;
//         for(auto &[neigh,weight]:adj[node]){
//             if(!visited[neigh])pq.push({weight,neigh,node});
//         }
//        }
//        return totalcost;
//     }
// };