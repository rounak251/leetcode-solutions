class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int i=0;int j=n-1;int count=0;
        sort(people.begin(),people.end());
        while(i<=j){
           if(people[i]+people[j]<=limit){
            i++;j--;
           }
           else{
            j--;
           }
           count++;
           
            
           
        }return count;
    }
};
// int n=people.size();
//         int i=0;long long int sum=0;int count=0;
//         sort(people.begin(),people.end());
//         while(i<n){
//             sum=people[i];
           
//              if( i+1<n&& sum+people[i+1]<=limit){
//                 sum+=people[i+1];
//                 i++;
//             }
//             count++;i++;
//         }return count;
//     }