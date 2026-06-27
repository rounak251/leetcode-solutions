class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>lost;
        for(auto &it:matches){
            int loss=it[1];
            lost[loss]++;
        }
        vector<int>notloss;
        vector<int>onceloss;
        for(auto &it:matches){
            if(lost.find(it[0])==lost.end()){
                notloss.push_back(it[0]);
                lost[it[0]]=2;
            }
            if(lost[it[1]]==1){
                onceloss.push_back(it[1]);
            }
        }
        sort(notloss.begin(),notloss.end());
         sort(onceloss.begin(),onceloss.end());
         return {notloss,onceloss};
    }
};