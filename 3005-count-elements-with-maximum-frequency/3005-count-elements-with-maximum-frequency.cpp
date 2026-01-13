class Solution {
public:
    int maxFrequencyElements(vector<int>& arr) {
        int n=arr.size();
        int maxfreq=0;vector<int>result(101,0);
        for(auto &it:arr){
result[it]++;
maxfreq=max(maxfreq,result[it]);
        }int count=0;
        for(int i=0;i<101;i++){
if(result[i]==maxfreq) count+=maxfreq;
        }return count;
    }
};