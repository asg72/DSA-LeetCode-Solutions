class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> seen;

        int low = 0;
        int high = 0;
        int maxLen = 0;

        while (high < n) {
            seen[s[high]]++;

            while (seen[s[high]] > 1) {
                seen[s[low]]--;
                if (seen[s[low]] == 0) {
                    seen.erase(s[low]);
                }
                    low++;
            }

            maxLen = max(maxLen, high - low + 1);
            high++;
        }

        return maxLen;
    }
};