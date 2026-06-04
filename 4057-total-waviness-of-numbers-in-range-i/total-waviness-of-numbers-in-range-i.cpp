class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int totalWaviness = 0;
        
        // A number must be at least 100 to have 3 digits. 
        // We can safely push the starting point to 100 if num1 is smaller.
        int start = max(100, num1);
        
        for (int i = start; i <= num2; i++) {
            string s = to_string(i);
            int n = s.length();
            
            // Loop through the middle digits
            for (int j = 1; j < n - 1; j++) {
                
                // Storing the conditions in descriptively named boolean variables 
                // makes the code "self-documenting" and incredibly easy to read.
                bool isPeak = (s[j] > s[j - 1] && s[j] > s[j + 1]);
                bool isValley = (s[j] < s[j - 1] && s[j] < s[j + 1]);
                
                if (isPeak || isValley) {
                    totalWaviness++;
                }
            }
        }
        
        return totalWaviness;
    }
};