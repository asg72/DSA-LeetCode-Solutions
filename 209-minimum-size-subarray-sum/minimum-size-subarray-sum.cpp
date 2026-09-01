class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int low = 0, high = 0;
        int sum = 0, len = 0;
        int min_len = INT_MAX;

        while (high < n) {
            sum += nums[high];

            while (sum >= target) {
                min_len = min(min_len, high - low + 1);
                sum -= nums[low];
                low++;
            }

            high++;
        }

        if (min_len == INT_MAX) {
            return 0;
        }

        return min_len;
    }
};