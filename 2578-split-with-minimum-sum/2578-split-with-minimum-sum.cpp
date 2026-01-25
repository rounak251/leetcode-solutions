class Solution {
public:
    int splitNum(int num) {
        vector<int>temp;
        while(num!=0){

            temp.push_back(num%10);
           num= num/10;
        }sort(temp.begin(),temp.end());
        int n1=0;int n2=0;
        for(int i=0;i<temp.size();i++){
            if(i%2==0) n1=n1*10+temp[i];
            else n2=n2*10+temp[i];
        }return n1+n2;
    }
};