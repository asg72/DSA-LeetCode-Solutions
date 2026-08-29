class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        // 1. Sort the entire array
        sort(nums.begin(), nums.end());
        
        // Initialize with the sum of the first three elements
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                // Update closest sum if the current sum is closer to target
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }
                
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    j++; // Need a larger sum
                } else {
                    k--; // Need a smaller sum
                }
            }
        }
        
        return closestSum;
    }
};