class Solution {
public:
    int minimumCost(vector<int>& cost) {
        // 1. Sort in ascending order so the most expensive candies are at the end
        sort(cost.begin(), cost.end());
        
        int totalCost = 0;
        
        // 2. Buy candies in groups of 3, starting from the most expensive
        for (int i = cost.size() - 1; i >= 0; i -= 3) {
            // Always pay for the 1st most expensive candy in the triplet
            totalCost += cost[i];
            
            // If a 2nd candy exists in this triplet, pay for it too
            if (i - 1 >= 0) {
                totalCost += cost[i - 1];
            }
            
            // The 3rd candy (at index i - 2) is skipped entirely because it's free!
        }
        
        return totalCost;
    }
};
