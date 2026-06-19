class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;
        
        int i = 0;
        
        // 1. Climb up the mountain
        while (i + 1 < n && arr[i] < arr[i + 1]) {
            i++;
        }
        
        // The peak cannot be the first element or the last element
        if (i == 0 || i == n - 1) {
            return false;
        }
        
        // 2. Climb down the mountain
        while (i + 1 < n && arr[i] > arr[i + 1]) {
            i++;
        }
        
        // If we successfully reached the end, it's a valid mountain
        return i == n - 1;
    }
};