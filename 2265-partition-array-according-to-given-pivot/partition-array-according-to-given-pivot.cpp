class Solution {
public:
    vector<int> pivotArray(vector<int>& arr, int p) {
        int n = arr.size();
        vector<int> ans(n, p); // Pre-fill the array with the pivot value
        
        int left = 0;
        int right = n - 1;
        
        // Single pass from both ends
        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            if (arr[i] < p) {
                ans[left++] = arr[i];
            }
            if (arr[j] > p) {
                ans[right--] = arr[j];
            }
        }
        
        return ans;
    }
};
