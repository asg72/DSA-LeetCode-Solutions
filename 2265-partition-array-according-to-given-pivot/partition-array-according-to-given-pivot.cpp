class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result;
        result.reserve(nums.size()); // Optimize memory allocation

        // Pass 1: Collect elements less than pivot
        for (int num : nums) {
            if (num < pivot) {
                result.push_back(num);
            }
        }

        // Pass 2: Collect elements equal to pivot
        for (int num : nums) {
            if (num == pivot) {
                result.push_back(num);
            }
        }

        // Pass 3: Collect elements greater than pivot
        for (int num : nums) {
            if (num > pivot) {
                result.push_back(num);
            }
        }

        return result;
    }
};