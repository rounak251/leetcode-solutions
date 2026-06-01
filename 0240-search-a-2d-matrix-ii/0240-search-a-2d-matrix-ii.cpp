class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
       
        int r =n-1;int l=0;
        while(l<m && r>=0 ){
            if(matrix[l][r]==target)return true;
            if(matrix[l][r]>target) r=r-1;
           else if(matrix[l][r]<target) l=l+1;
        }
        return false;
    }
};