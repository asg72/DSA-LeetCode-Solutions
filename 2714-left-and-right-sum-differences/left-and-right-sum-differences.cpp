class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> leftSum(n);
        vector<int> rightSum(n);
        vector<int> ans(n);
        
        // 1. Calculate prefix sums moving from left to right
        leftSum[0] = 0;
        for (int i = 1; i < n; i++) {
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
        }

        // 2. Calculate suffix sums moving from right to left
        rightSum[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            rightSum[i] = rightSum[i + 1] + nums[i + 1];
        }

        // 3. Compute the absolute differences
        for (int i = 0; i < n; i++) {
            ans[i] = abs(leftSum[i] - rightSum[i]);
        }

        return ans;
    }
};