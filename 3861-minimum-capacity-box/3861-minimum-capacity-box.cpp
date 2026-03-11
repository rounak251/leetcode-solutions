class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int min = INT_MAX;
        int index = -1;

        for (int i = 0; i < capacity.size(); i++) {
            if (capacity[i] >= itemSize) {
                if (capacity[i] < min) {
                    min = capacity[i];
                    index = i;
                }}}return index; }
};