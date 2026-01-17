class Solution {
public:
    int numberOfMatches(int n) {
        int matches=0;
        int teamadvance=n;
        while(teamadvance!=1){
            if(teamadvance%2==0){
                matches+=teamadvance/2;
                teamadvance=teamadvance/2;
            }
            else{

matches+=(teamadvance-1)/2;
teamadvance=(teamadvance-1)/2+1;
            }
        }return matches;
        
    }
};