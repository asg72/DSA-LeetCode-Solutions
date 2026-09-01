class Solution {
  public:
    int longestKSubstr(string s, int k) {
        int n = s.length();

        // Step 1: Create a hash map to track the frequency of characters in our current window
        unordered_map<char, int> f; 

        int low = 0;
        int high = 0;

        // Step 2: Initialize max_len to -1. 
        // If we never find a substring with exactly 'k' unique characters, it correctly returns -1.
        int max_len = -1; 

        // Step 3: Expand the window to the right by moving the 'high' pointer
        while(high < n){
            // Add the current character at 'high' to our frequency map
            f[s[high]]++;

            // Step 4: If our window has more than 'k' unique characters, we must shrink it
            while(f.size() > k){
                // Decrease the frequency of the character at the 'low' pointer
                f[s[low]]--;

                // If the frequency hits 0, remove it from the map so f.size() updates correctly
                if(f[s[low]] == 0){
                    f.erase(s[low]);
                }

                // Move the 'low' pointer forward to actually shrink the window's size
                low++; 
            }

            // Step 5: If the window has exactly 'k' unique characters, check if it's the longest one yet
            if(f.size() == k){
                int len = high - low + 1; // Calculate current window length
                max_len = max(max_len, len); // Update max_len if this one is longer
            }

            // Step 6: Move the 'high' pointer forward to continue looking through the string
            high++; 
        }

        // Step 7: Return the largest valid length we found
        return max_len;
    }
};