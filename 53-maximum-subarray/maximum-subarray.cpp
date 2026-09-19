class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestEndin = nums[0];
        int res = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int v1 = nums[i];
            int v2 = bestEndin + nums[i];
            bestEndin = max(v1, v2);
            res = max(res, bestEndin);
        }
        return res;
    }
};