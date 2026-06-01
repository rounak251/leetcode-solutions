

class Solution {
public:
    bool binary_search(vector<int>& arr, int l, int h, int target) {
        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (arr[mid] == target)
                return true;
            else if (arr[mid] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return false;
    }

    int pivot_index(vector<int>& arr, int n) {
        int l = 0, h = n - 1;
while(l<h && arr[l]==arr[l+1])l++;
while(l<h && arr[h]==arr[h-1])h--;
        while (l < h) {
            int mid = l + (h - l) / 2;

            if (arr[mid] > arr[h])
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }

    int search(vector<int>& arr, int target) {
        int n = arr.size();

        int index = pivot_index(arr, n);

        bool inx1 = binary_search(arr, 0, index - 1, target);
        bool inx2 = binary_search(arr, index, n - 1, target);

        if (inx1 != false) return inx1;
        return inx2;
    }
};

// class Solution {
// public:
//     int search(vector<int>& arr, int target) {
//         int n=arr.size();
//    int low=0;int high=n-1;

//    while(low<=high){
//     int mid=low+(high-low)/2;if(arr[mid]==target)return true;
//        if(arr[low]==arr[mid]&&arr[mid]==arr[high]){low++;high--;continue;}
    
//     if(arr[low]<=arr[mid]){
// if(arr[low]<=target && target<=arr[mid]) high=mid-1;
// else low=mid+1;
//     }
//     else{
//         if(arr[mid]<=target && target<=arr[high]) low=mid+1;
//         else high=mid-1;

//     }
//    }return false;
//     }
// };