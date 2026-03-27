class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string>s(n);
        vector<int>arr=score;

        sort(arr.begin(), arr.end(), greater<int>());
        unordered_map<int,int>rank;
        for(int i=0;i<n;i++){
            rank[arr[i]]=i+1;
        }
      
        for(int i=0;i<n;i++){
            int r=rank[score[i]];
            if(r==1) s[i]="Gold Medal";
            else if(r==2) s[i]="Silver Medal";
            else if(r==3)s[i]="Bronze Medal";
            else s[i]=to_string(r);

        }
        return s;
    }
};