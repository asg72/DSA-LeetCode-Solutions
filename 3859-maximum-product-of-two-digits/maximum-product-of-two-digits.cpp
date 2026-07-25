class Solution {
public:
    int maxProduct(int n) {
        int max1 = 0; // Highest digit
        int max2 = 0; // Second highest digit
        
        while (n > 0) {
            int digit = n % 10; // Extract the last digit
            
            if (digit > max1) {
                max2 = max1;  // The old highest becomes the new second highest
                max1 = digit; // Update the highest digit
            } else if (digit > max2) {
                max2 = digit; // Update the second highest digit
            }
            
            n /= 10; // Remove the last digit
        }
        
        return max1 * max2;
    }
};