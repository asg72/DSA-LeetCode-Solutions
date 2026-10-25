#include <string>
#include <algorithm>

class Solution {
public:
        string mergeAlternately(std::string word1, std::string word2) {
        string mergedResult = "";
        int i = 0, j = 0;
        int len1 = word1.length();
        int len2 = word2.length();

        // Alternately append characters from both strings
        while (i < len1 && j < len2) {
            mergedResult += word1[i++];
            mergedResult += word2[j++];
        }

        // Append any remaining characters from word1
        while (i < len1) {
            mergedResult += word1[i++];
        }

        // Append any remaining characters from word2
        while (j < len2) {
            mergedResult += word2[j++];
        }

        return mergedResult;
    }
};