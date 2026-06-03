class Solution {
public:
int lowers(int l,int r,vector<int>&potions,long long minpotion){
    int possindex=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(potions[mid]>=minpotion){
            possindex=mid;
            r=mid-1;
        }else l=mid+1;
    }
    return possindex;
}
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>result;
        int n=spells.size();
        int m=potions.size();
        sort(potions.begin(),potions.end());
        long long maxpotion=potions[m-1];
        for(int i=0;i<n;i++){
            long long minpotion=ceil((1.0*success)/spells[i]);
            if(maxpotion<minpotion){
                result.push_back(0);
                continue;
            }
            //lowerbound check if minpotion>=potion[i]
            int index= lowers(0,m-1,potions,minpotion);
            result.push_back(m-index);
        }
        return result;
    }
};