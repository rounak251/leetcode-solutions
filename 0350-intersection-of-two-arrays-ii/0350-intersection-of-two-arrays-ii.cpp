class Solution {
public:
    vector<int> intersect(vector<int>& num1, vector<int>& num2) {
        int i=0;int j=0;vector<int>ans;
        sort(num1.begin(),num1.end());
        sort(num2.begin(),num2.end());
        while(i<num1.size() && j<num2.size()){
     if(num1[i]==num2[j]) {ans.push_back(num1[i]);i++;j++;}
     else if(num1[i]<num2[j])i++;
     else j++;
        }return ans;
    }
};