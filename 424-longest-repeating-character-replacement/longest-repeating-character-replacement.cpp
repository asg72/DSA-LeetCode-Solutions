class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int f[256] = {0};

        int low = 0, high = 0, maxLen = 0;

        while (high < n) {
            f[s[high]]++;

            int len = high - low + 1;
            int maxFreq = *std::ranges::max_element(f);
            int diff = len - maxFreq;

            while (diff > k) {
                f[s[low]]--;
                low++;

                len = high - low + 1;
                // maxFreq = *std::ranges::max_element(f);
                diff = len - maxFreq;
            }

            maxLen = max(maxLen, high - low + 1);
            high++;
        }

        return maxLen;
    }
};