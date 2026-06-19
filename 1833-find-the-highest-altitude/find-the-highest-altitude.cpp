class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_altitude = 0;
        int current_altitude = 0;
        
        // A simple range-based for loop works perfectly here
        for (int g : gain) {
            current_altitude += g; // Update to the next altitude
            max_altitude = max(max_altitude, current_altitude); // Check if it's the highest
        }
        
        return max_altitude;
    }
};