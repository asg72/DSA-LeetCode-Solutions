#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Finds the maximum number of ice cream bars that can be bought.
     * Uses a Counting Sort (Greedy) approach for optimal performance.
     * * Time Complexity:  O(N + M) where N is the number of ice cream bars and M is the maximum cost.
     * Space Complexity: O(M) for the frequency array.
     */
    int maxIceCream(vector<int>& costs, int coins) {
        // Step 1: Find the maximum cost to size the frequency array
        int max_val = 0;
        for (int cost : costs) {
            max_val = max(max_val, cost);
        }

        // Step 2: Create a frequency array to count occurrences of each cost
        vector<int> freq(max_val + 1, 0);
        for (int cost : costs) {
            freq[cost]++;
        }

        int max_ice_creams = 0;

        // Step 3: Greedily buy the cheapest ice creams first
        for (int cost = 1; cost <= max_val; ++cost) {
            if (freq[cost] == 0) {
                continue;
            }

            // If we can't afford even one of the current cost, stop buying
            if (coins < cost) {
                break;
            }

            // Calculate how many ice creams of this cost we can buy
            // We can either buy all of them, or as many as our coins allow
            int count = min(freq[cost], coins / cost);
            
            coins -= count * cost;
            max_ice_creams += count;
        }

        return max_ice_creams;
    }
};