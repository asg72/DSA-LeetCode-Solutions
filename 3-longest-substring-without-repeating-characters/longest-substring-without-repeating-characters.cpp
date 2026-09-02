class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        // A simple array tracking frequencies of all 256 possible ASCII characters
        int seen[256] = {0}; 

        int low = 0, high = 0, maxLen = 0;

        while (high < n) {
            seen[s[high]]++;

            while (seen[s[high]] > 1) {
                seen[s[low]]--; // No need to erase! A count of 0 is perfectly fine here.
                low++;
            }

            maxLen = max(maxLen, high - low + 1);
            high++;
        }

        return maxLen;
    }
};
