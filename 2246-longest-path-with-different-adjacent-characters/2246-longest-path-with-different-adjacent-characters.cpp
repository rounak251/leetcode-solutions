class Solution {
public:
int result;
int dfs(unordered_map<int,vector<int>>&adj,int curr,int parent,string &s){
    int longest=0;
    int secondlongest=0;
    for(auto &child:adj[curr]){
        if(child==parent)continue;
        int child_longest_length=dfs(adj,child,curr,s);
        if(s[child]==s[curr])continue;
        if(child_longest_length>secondlongest)secondlongest=child_longest_length;
        if(secondlongest>longest)swap(secondlongest,longest);
    }
    int neeche_ans=longest+secondlongest+1;
    int anyone=max(longest,secondlongest)+1;
    int oneroot=1;
    result=max({result,neeche_ans,anyone,oneroot});
    return max(anyone,oneroot);

}
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        unordered_map<int,vector<int>>adj;
        result=0;
        for(int i=1;i<n;i++){
            int u=i;
            int v=parent[i];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        dfs(adj,0,-1,s);
        return result;
    }
};