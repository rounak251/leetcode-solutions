class Solution {
public:
    int majorityElement(vector<int>& arr) {
         int n =arr.size();
    int el;
    int cn=0;
    for (int i = 0; i < n; i++)
    {
        /* code */ if (cn==0){
            el=arr[i];
            cn=1;
        }
        else if(arr[i]==el) cn++;
        else cn--;
    }
    int cn1=0;
    for (int i = 0; i < n; i++)
    {
        /* code */ if ( arr[i]==el)cn1++;
}
 if (cn1>(n/2)) return el;
 return -1;}
};