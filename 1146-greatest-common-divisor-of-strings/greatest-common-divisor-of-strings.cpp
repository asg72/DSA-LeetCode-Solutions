class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // If they don't match when flipped, they share no common divisor string
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        
        // Find the GCD of the two lengths
        int gcdLength = gcd(str1.length(), str2.length());
        
        // Return the prefix of that length
        return str1.substr(0, gcdLength);
    }
};