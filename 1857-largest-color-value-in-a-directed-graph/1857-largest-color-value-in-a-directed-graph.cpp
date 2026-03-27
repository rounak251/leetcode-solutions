class Solution {
public:
    int largestPathValue(string color, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        int N=color.size();
        vector<int>indegree(N,0);
        for(auto &edge:edges){
            int u=edge[0];int v=edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<vector<int>>t(N,vector<int>(26,0));
        queue<int>que;
        for(int i=0;i<N;i++){
            if(indegree[i]==0){
            que.push(i);
            t[i][color[i]-'a']=1;
            }
        }
        int answer=0;int countnodes=0;
        while(!que.empty()){
            int node=que.front();que.pop();countnodes++;
            answer=max(answer,t[node][color[node]-'a']);
            for(auto &v :adj[node]){
                for(int i=0;i<26;i++){
              t[v][i]=max(t[v][i],t[node][i]+(color[v]-'a'==i));}
          
            indegree[v]--;
            if(indegree[v]==0)que.push(v);}

        }
        if(countnodes<N)return -1;
        return answer;




    }
};