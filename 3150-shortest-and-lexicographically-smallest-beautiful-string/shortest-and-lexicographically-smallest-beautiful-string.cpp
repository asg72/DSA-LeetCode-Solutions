class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string best_str = "";
        int minlen = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int count = 0;
            string curr_str = "";

            for (int j = i; j < n; ++j) {
                curr_str+=s[j];
                if(s[j] == '1'){
                    count++;                   
                }
                // Once we have exactly k ones, evaluate this candidate
                if(count == k){
                    int curr_len = curr_str.size();

                    if(minlen > curr_len){
                        // Rule 1: Found a strictly shorter valid substring
                        minlen = curr_len;
                        best_str = curr_str;
                    }
                    else if(minlen == curr_len){
                        // Rule 2: Same length, check if lexicographically smaller
                        if(best_str == "" || curr_str < best_str){
                            best_str = curr_str;
                        }
                    }

                    // Since any further expansion from 'i' will only make the string longer,
                    // we can break early and move 'i' forward.
                    break;
                }

            }

       }

       return best_str;

    }
};