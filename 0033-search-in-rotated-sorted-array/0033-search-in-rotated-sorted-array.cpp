class Solution {
public:
    int binary_search(vector<int>& arr, int l, int h, int target) {
        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (arr[mid] == target)
                return mid;
            else if (arr[mid] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return -1;
    }

    int pivot_index(vector<int>& arr, int n) {
        int l = 0, h = n - 1;

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

        int inx1 = binary_search(arr, 0, index - 1, target);
        int inx2 = binary_search(arr, index, n - 1, target);

        if (inx1 != -1) return inx1;
        return inx2;
    }
};

// int low=0;int high=n-1;
//    while(low<=high){
//     int mid=low+(high-low)/2;
//     if(arr[mid]==target)return mid;
//     if(arr[low]<=arr[mid]){
// if(arr[low]<=target && target<=arr[mid]) high=mid-1;
// else low=mid+1;
//     }
//     else{
//         if(arr[mid]<=target && target<=arr[high]) low=mid+1;
//         else high=mid-1;

//     }
//    }return -1;