class Solution {
public:
   int countMajoritySubarrays(const vector<int>& nums, int target) {
    int arraySize = nums.size();
    int validSubarrayCount = 0; 
    
    for (int startIndex = 0; startIndex < arraySize; startIndex++) {
        int targetCount = 0; 
        
        for (int endIndex = startIndex; endIndex < arraySize; endIndex++) {
            
            if (nums[endIndex] == target) {
                targetCount++;
            }
            
            int windowSize = endIndex - startIndex + 1;
            
            // A majority element strictly appears more than half the time
            if (targetCount > (windowSize / 2)) {
                validSubarrayCount++;
            }
        }
    }
    
    return validSubarrayCount;
}
};