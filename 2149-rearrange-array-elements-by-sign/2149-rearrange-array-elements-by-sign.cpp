class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n =arr.size();
          vector<int> pos,neg;
    for (int i = 0; i < n; i++)
    {
        /* code */ if(arr[i]<0){
            neg.push_back(arr[i]);
        }
        else{
            pos.push_back(arr[i]);
        }
    }
    
    int m =min(pos.size(),neg.size());
  
    for (int i = 0; i < m; i++)
    {
        /* code */ arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];

    }
    int index=2*m;
    
    for (int i = m; i <pos.size() ; i++)
    {
        /* code */ arr[index]=pos[i];
        
    }
    for (int i = m; i <neg.size() ; i++)
    {
        /* code */ arr[index]=neg[i];
        
    }
    return arr;
    }
};