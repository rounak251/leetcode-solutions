class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
      int n=arr.size();
      int l=0;int h=n-1;

      while(l<h){
        int mid=l+(h-l)/2;
        bool iseven;
        if((h-mid)%2==0) iseven=true;
        else iseven=false;
        if(arr[mid]==arr[mid+1]){
           if(iseven){
              l=mid+2;
           }
           else{
            h=mid-1;

           }
        }else{
            if(iseven){
              h=mid;
           }
           else{
            l=mid+1;

           }

        }
      }

return arr[h];
    }
};

//  int ans=0;
//         for(int i=0;i<nums.size();i++){
// ans=ans^nums[i];
//         }
//         return ans;