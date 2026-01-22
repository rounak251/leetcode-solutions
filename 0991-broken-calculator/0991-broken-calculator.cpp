class Solution {
public:
    int brokenCalc(int sv, int t) {
        long long S = sv; 
        long long T = t;
        int oper = 0;

        while(T != S) {
            if(T > S) {
                if(T % 2 == 0) T /= 2;
                else T++; 
                oper++;
            } else {
                oper += (S - T); 
                break;
            }
        }

        return oper;
    }
};
