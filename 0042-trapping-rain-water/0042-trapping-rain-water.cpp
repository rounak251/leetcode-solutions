class Solution {
public:
    int trap(vector<int>& height) {
//         int n=height.size();
//         vector<int>leftmax(n);
//         vector<int>rightmax(n);
//         leftmax[0]=height[0];
//         for(int i=1;i<n;i++){
//             leftmax[i]=max(leftmax[i-1],height[i]);

//         }
//         rightmax[n-1]=height[n-1];
//         for(int i=n-2;i>=0;i--){
//             rightmax[i]=max(rightmax[i+1],height[i]);
//         }
//         int water =0;
//         for(int i=0;i<n;i++){
//             water+=min(rightmax[i],leftmax[i])-height[i];
//         }
//  return water;
//     }
    int n=height.size();
    int l=0;int r=n-1;
    int leftmax=0;int rightmax=0;int water =0;
    while(l<r){
        if(height[l]<height[r]){
        if(height[l]>leftmax)leftmax=height[l];
        else water+=leftmax-height[l];
        l++;
        }else{
            if(height[r]>rightmax)rightmax=height[r];
            else water+=rightmax-height[r];
            r--;

        }}
        return water;
    }
};