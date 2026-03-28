class Solution {
public:
void dfs( unordered_map<string,vector<pair<string,double>>>&adj,string src,string dst,unordered_set<string>&visited,double &ans,double product){
if(visited.find(src)!=visited.end()) return;
visited.insert(src);
if(src==dst) ans=product;
for(auto &p:adj[src]){
    string v=p.first;
    double val=p.second;
    dfs(adj,v,dst,visited,ans,product*val);
}


}
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        unordered_map<string,vector<pair<string,double>>>adj;
        for(int i=0;i<n;i++){
            
                string u=equations[i][0];
                string v=equations[i][1];
                double wt=values[i];
                adj[u].push_back({v,wt});
                  adj[v].push_back({u,(1.0/wt)});
            
        }
       
      
        vector<double>result;
        for(auto &query:queries){
            string src=query[0];
            string dst=query[1];
            double ans=-1.0;
            double product=1.0;
            if(adj.find(src)!=adj.end() ){
                unordered_set<string>visited;

                dfs(adj,src,dst,visited,ans,product);
            }
            result.push_back(ans);
        }

return result;

    }
};