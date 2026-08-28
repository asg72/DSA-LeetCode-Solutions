class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr(n,0);

        int st = 0;
        int end = n - 1;
        int write = end;

        while (st <= end) {
            if (abs(nums[st]) < abs(nums[end])) {
                arr[write] = nums[end] * nums[end];
                write--;
                end--;
            } else if (abs(nums[st]) >= abs(nums[end])) {
                arr[write] = nums[st] * nums[st];
                write--;
                st++;
            }
        }
        return arr;
    }
};