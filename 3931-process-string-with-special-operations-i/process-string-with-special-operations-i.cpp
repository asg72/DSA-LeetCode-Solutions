class Solution {
public:
    string processStr(string s) {
        string result = "";
        
        for (char ch : s) {
            if (ch == '*') {
                // Defensive check to prevent popping from an empty string
                if (!result.empty()) {
                    result.pop_back();
                }
            } 
            else if (ch == '#') {
                // Duplicates the current string and appends it to itself
                result += result;
            } 
            else if (ch == '%') {
                // Reverses the current string in-place
                reverse(result.begin(), result.end());
            } 
            else {
                // Normal lowercase English letters
                result.push_back(ch);
            }
        }
        
        return result;
    }
};