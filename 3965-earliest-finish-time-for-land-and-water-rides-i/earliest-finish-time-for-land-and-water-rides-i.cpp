class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        // Initialize with a large number since we are looking for the minimum
        int earliestTime = 2e9; 

        // Loop through every land ride
        for (int i = 0; i < n; ++i) {
            // Loop through every water ride
            for (int j = 0; j < m; ++j) {
                
                // --- Option 1: Land first, then Water ---
                int landFinish = landStartTime[i] + landDuration[i];
                // Using your logic, simplified with max()
                int totalLW = max(landFinish, waterStartTime[j]) + waterDuration[j];
                
                // --- Option 2: Water first, then Land ---
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int totalWL = max(waterFinish, landStartTime[i]) + landDuration[i];
                
                // Keep track of the absolute fastest time we've seen so far
                earliestTime = min({earliestTime, totalLW, totalWL});
            }
        }
        
        return earliestTime;
    }
};