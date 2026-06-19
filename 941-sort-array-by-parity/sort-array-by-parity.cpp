class Solution {
public:
    vector<int>& sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            // If left is already even, just move forward
            if (nums[left] % 2 == 0) {
                left++;
            } 
            // If right is already odd, just move backward
            else if (nums[right] % 2 != 0) {
                right--;
            } 
            // If left is odd and right is even, swap them!
            else {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        return nums;
    }
};