class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        // --- Strategy 1: Land Ride First, then Water Ride ---
        // Step 1: Find the land ride that finishes as early as possible
        int minLandFinish = INT_MAX;
        for (int i = 0; i < n; ++i) {
            minLandFinish = min(minLandFinish, landStartTime[i] + landDuration[i]);
        }
        
        // Step 2: Pair this optimal land ride with the best available water ride
        int option1 = INT_MAX;
        for (int j = 0; j < m; ++j) {
            int totalTime = max(minLandFinish, waterStartTime[j]) + waterDuration[j];
            option1 = min(option1, totalTime);
        }
        
        // --- Strategy 2: Water Ride First, then Land Ride ---
        // Step 1: Find the water ride that finishes as early as possible
        int minWaterFinish = INT_MAX;
        for (int j = 0; j < m; ++j) {
            minWaterFinish = min(minWaterFinish, waterStartTime[j] + waterDuration[j]);
        }
        
        // Step 2: Pair this optimal water ride with the best available land ride
        int option2 = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int totalTime = max(minWaterFinish, landStartTime[i]) + landDuration[i];
            option2 = min(option2, totalTime);
        }
        
        // The answer is the best outcome between both strategy sequences
        return min(option1, option2);
    }
};