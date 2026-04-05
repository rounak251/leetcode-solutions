class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
int n=nums.size();
int m=floor(n/3);
unordered_map<int,int>mp;
for(int i=0;i<n;i++){
    mp[nums[i]]++;
}
vector<int>arr;
for(auto &x:mp){
    int c=x.first;
    int v=x.second;
    if(v>m) arr.push_back(c);


}
return arr;
    }
};