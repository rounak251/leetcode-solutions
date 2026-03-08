class Solution {
public:
int n;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n=numCourses;
        vector<int>indegree(n,0);
        unordered_map<int,vector<int>>adj;
        for(auto &edge:prerequisites){
            int a=edge[0];
            int b=edge[1];
            adj[b].push_back(a);
            indegree[a]++;

        }
        vector<int> result;queue<int>que;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                que.push(i);

            }
        }while(!que.empty()){
            int u=que.front();que.pop();result.push_back(u);
            for(auto &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0) que.push(v);
            }
        }
        if(result.size()!=n)return {};
return result;
    }
};