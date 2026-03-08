class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0);

        // build graph
        for(auto &edge : prerequisites){
            int a = edge[0];
            int b = edge[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q; int count = 0;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                {q.push(i); count++;}
        }

       

        while(!q.empty()){
            int node = q.front();
            q.pop();
           

            for(auto &v : adj[node]){
                indegree[v]--;

                if(indegree[v]==0)
                  { q.push(v); count++;}
            }
        }

        return count == numCourses;
    }
};