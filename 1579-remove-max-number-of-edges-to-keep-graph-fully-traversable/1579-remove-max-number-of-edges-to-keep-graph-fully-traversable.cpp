
class DSU{
    public:
   vector<int>parent;
vector<int>rank;
int components;
DSU(int n){
    parent.resize(n+1);
    rank.resize(n+1);
    for(int i=1;i<=n;i++)parent[i]=i;
    components=n;
}
int find(int x){
    if(parent[x]==x)return x;
    return parent[x]=find(parent[x]);
}
void unite(int x,int y){
    int x_parent=find(x);
    int y_parent=find(y);
    if(x_parent==y_parent)return;
    if(rank[x_parent]>rank[y_parent]) parent[y_parent]=x_parent;
    else if(rank[x_parent]<rank[y_parent]) parent[x_parent]=y_parent;
    else{
        parent[x_parent]=y_parent;
        rank[y_parent]++;
    }components--;
}
bool singlecomponent(){
    return components==1;
}
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n);
        DSU bob(n);
        auto lamda =[&](vector<int>&v1,vector<int>&v2){
            return v1[0]>v2[0];

        };

        sort(edges.begin(),edges.end(),lamda);
int edgecount=0;
for(auto &vec:edges){
    int type=vec[0];int u=vec[1];int v=vec[2];
    if(type==3){
        bool addedge=false;
        if(alice.find(u)!=alice.find(v)){
            alice.unite(u,v);addedge=true;
        }
        if(bob.find(u)!=bob.find(v)){
           bob.unite(u,v);addedge=true;
        }
        if(addedge==true) edgecount++;
    }
else if(type==2){
    if(bob.find(u)!=bob.find(v)){
           bob.unite(u,v);edgecount++;
        }
}
else{
     if(alice.find(u)!=alice.find(v)){
           alice.unite(u,v);edgecount++;
        }
}


}

if(alice.singlecomponent()==true && bob.singlecomponent()==true)
return edges.size()-edgecount;


return -1;

    }
};