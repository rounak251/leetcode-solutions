class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {int n=nums.size();
      //  vector<int>nums;
        vector<int>v;
       for(int i=0;i<n;i++){
            if(nums[i]>=0)v.push_back(nums[i]);
        }
        int m=v.size();
        if(m==0) return nums;
            k=k%m;                                             // rotate(v.begin(),v.begin()+k,v.end());
                                                          vector<int>rot(m);
                                                          for(int i=0;i<m;i++){
                                                              rot[i]=v[(i+k)%m];
                                                          }
         int j=0;                                                 for(int i=0;i<n;i++){
              if(nums[i]>=0){
                  nums[i]=rot[j];j++;
              }  }                                              return nums;
                                                          
            
    }
};