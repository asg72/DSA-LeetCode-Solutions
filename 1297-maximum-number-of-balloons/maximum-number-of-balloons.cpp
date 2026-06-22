class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // A frequency array acting as a direct-address hash table
        vector<int> counts(26, 0);
        
        // Populate the frequency map
        for (char c : text) {
            counts[c - 'a']++;
        }
        
        // Find the bottleneck character
        int b_count = counts['b' - 'a'];
        int a_count = counts['a' - 'a'];
        int l_count = counts['l' - 'a'] / 2; // Requires 2 'l's per balloon
        int o_count = counts['o' - 'a'] / 2; // Requires 2 'o's per balloon
        int n_count = counts['n' - 'a'];
        
        // Return the minimum of these counts
        return min({b_count, a_count, l_count, o_count, n_count});
    }
};