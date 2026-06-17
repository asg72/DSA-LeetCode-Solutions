class Solution {
public:
    char processStr(string s, long long k) {
        vector<long long> lengths;
        long long current_len = 0;
        
        // Pass 1: Compute the exact length history (No capping needed!)
        for (char ch : s) {
            if (ch == '*') {
                if (current_len > 0) current_len--;
            } else if (ch == '#') {
                current_len *= 2;
            } else if (ch == '%') {
                // Length stays the same
            } else {
                current_len++;
            }
            lengths.push_back(current_len);
        }
        
        // If k is out of bounds of the final string
        if (k >= current_len || k < 0) return '.';
        
        // Pass 2: Reverse engineer k by unwinding operations from the end
        for (int i = s.length() - 1; i >= 0; i--) {
            char ch = s[i];
            long long prev_len = (i > 0) ? lengths[i-1] : 0;
            
            if (ch == '*') {
                current_len = prev_len; 
            } 
            else if (ch == '#') {
                k %= prev_len; 
                current_len = prev_len;
            } 
            else if (ch == '%') {
                k = current_len - 1 - k;
                current_len = prev_len;
            } 
            else {
                if (k == current_len - 1) {
                    return ch;
                }
                current_len = prev_len;
            }
        }
        
        return '.';
    }
};