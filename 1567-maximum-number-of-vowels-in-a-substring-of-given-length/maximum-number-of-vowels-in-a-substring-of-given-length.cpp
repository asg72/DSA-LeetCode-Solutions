class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        if(n < k) return -1;
        
        // 1. Create a fast direct-lookup map for lowercase ASCII vowels
        bool is_vowel[256] = {false};
        is_vowel['a'] = is_vowel['e'] = is_vowel['i'] = is_vowel['o'] = is_vowel['u'] = true;
        
        int curVow = 0;
        
        // 2. Build the initial window of size k
        for(int i = 0; i < k; ++i) {
            if(is_vowel[static_cast<unsigned char>(s[i])]) {
                curVow++;
            }
        }
        
        int maxVow = curVow;
        
        // 3. Slide the window across the rest of the string
        for(int right = k; right < n; ++right) {
            int left = right - k;
            
            // Update the count efficiently
            if(is_vowel[static_cast<unsigned char>(s[right])]) curVow++;
            if(is_vowel[static_cast<unsigned char>(s[left])]) curVow--;
            
            // Track the maximum vowels found in any window
            maxVow = max(maxVow, curVow);
        }
        
        return maxVow;
    }
};