class Solution {
public:
    int missingNumber(vector<int>& arr) {
int n = arr.size();
    int xor1=0;
    int xor2=0;
    for (int i = 0; i < n; i++)
    {
        xor2=xor2^arr[i];
        xor1= xor1^(i+1);
        /* code */
    }
    return xor1^xor2;
    }
};
