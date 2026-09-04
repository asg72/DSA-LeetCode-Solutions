class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int zeroCount = 0, oneCount = 0;
        int high = 0, low = 0;
        int maxLen = 0;

        while (high < n) {
            if (nums[high] == 0)
                zeroCount++;
            else
                oneCount++;

            while (zeroCount > k) {
                if (nums[low] == 0) {
                    zeroCount--;
                }
                low++;
            }

            maxLen = max(maxLen, high - low + 1);
            high++;
        }
        return maxLen;
    }
};