class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long total_sum = 0;
        long long f_k = 0;
        int n = nums.size();
        
        // Step 1: Calculate Total Sum of elements and initial F(0)
        for (int i = 0; i < n; i++) {
            total_sum += nums[i];
            f_k += (long long)i * nums[i];
        }
        
        long long max_val = f_k;
        
        // Step 2: Use the rolling formula to find F(1) to F(n-1)
        for (int i = n - 1; i > 0; i--) {
            // F(k) = F(k-1) + total_sum - n * nums[i]
            f_k = f_k + total_sum - (long long)n * nums[i];
            
            // Keep track of the maximum value found
            max_val = max(max_val, f_k);
        }
        
        return max_val;
    }
};