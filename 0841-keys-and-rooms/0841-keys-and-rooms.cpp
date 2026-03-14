class Solution {
public:
void dfs(vector<vector<int>>& rooms,int u,vector<bool>&visited){
    visited[u]=true;
    for(auto & it:rooms[u]){
        if(!visited[it])dfs(rooms,it,visited) ; 
    } 
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       int n=rooms.size();
        vector<bool>visited(n,false);
        
       
        
 
        queue<int>que;
        que.push(0);
        visited[0]=true;
        while(!que.empty()){
            int node=que.front();que.pop();
            for(auto &it:rooms[node]){
                if(!visited[it]){
                    que.push(it);visited[it]=true;
                }
            }
        }
       // dfs(rooms,0,visited);
       for(auto x:visited){
        if(x==false)return false;
       }
    return true;}
};