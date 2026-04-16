class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
//best approuch
int l=0;
int h=(n*m)-1;
while(l<=h){
    int mid=l+(h-l)/2;
    if(matrix[mid/m][mid%m]==target)return true;
    if(matrix[mid/m][mid%m]<target) l=mid+1;
    else h=mid-1;

}


return false;}
// for(int i=0;i<n;i++){
//     int l=0;int r=m-1;
//     while(l<=r){
//         int mid=l+(r-l)/2;
//         if(matrix[i][mid]==target)return true;
//         else if(matrix[i][mid]>target){
//             r=mid-1;
//         }
//         else l=mid+1;
//     }

// }//by binary search
// int i=0;int j=m-1;
// while(i<n &&j>=0){
//     if(matrix[i][j]==target) return true;
//     if(matrix[i][j]>target)j--;
//     else i++;
// }
// return false;


//     }
};