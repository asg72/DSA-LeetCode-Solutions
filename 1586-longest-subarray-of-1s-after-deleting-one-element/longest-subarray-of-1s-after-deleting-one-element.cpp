class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int zeroCount = 0, oneCount = 0;
        int high = 0, low = 0;
        int maxLen = 0;

        while (high < n) {
            if (nums[high] == 1){
                oneCount++;
            }
            else{
                zeroCount++;
            }

            while (zeroCount > 1) {
                if (nums[low] == 0) {
                    zeroCount--;
                }
                low++;
            }

            maxLen = max(maxLen, high - low);
            high++;
        }
        return maxLen;
    }
};