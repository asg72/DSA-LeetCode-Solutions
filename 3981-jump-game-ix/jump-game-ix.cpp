class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefMax(n), suffMin(n), ans(n);

        // 1. Build the prefix maximum array
        prefMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }

        // 2. Build the suffix minimum array
        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        // 3. Find connected components and fill the max values
        int start = 0;
        while (start < n) {
            int end = start;
            int currentMax = nums[start];

            // Expand the component until we hit a valid cut/barrier
            while (end < n - 1 && prefMax[end] > suffMin[end + 1]) {
                end++;
                currentMax = max(currentMax, nums[end]);
            }

            // Fill all indices in the current component with its maximum value
            for (int k = start; k <= end; ++k) {
                ans[k] = currentMax;
            }

            // Move to the next component
            start = end + 1;
        }

        return ans;
    }
};