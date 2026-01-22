class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int maxscore=0;
        int score=0;
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int i=0;int j=n-1;
        while(i<=j){
            if(power>=tokens[i]){
                score++;
                power-=tokens[i];
                i++;
                maxscore=max(maxscore,score);
            }
            else if(score>=1){
                power+=tokens[j];
                score--;
                j--;

            }
            else break;
        }
        return maxscore;
    }
};