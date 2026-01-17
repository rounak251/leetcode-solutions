class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) { int n = matrix.size();        // rows
        int m = matrix[0].size(); 
        vector<vector<int>>arr(m,vector<int>(n));
     
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[j][i]=matrix[i][j];
            }
        }
        return arr;
    }
};