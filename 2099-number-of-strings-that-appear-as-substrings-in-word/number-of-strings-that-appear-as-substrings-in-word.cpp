class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        
        for (const string& pattern : patterns) {
            // Check if the current pattern is a substring of 'word'
            if (word.find(pattern) != string::npos) {
                count++;
            }
        }
        
        return count;
    }
};