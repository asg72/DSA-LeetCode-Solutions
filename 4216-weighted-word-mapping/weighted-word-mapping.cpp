class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
   string result = ""; 
    
    // Outer Loop: Go through each word
    for(int i = 0; i < words.size(); i++){
        string current_word = words[i];
        int sum = 0;
        
        // Inner Loop: Go through every character of the current word
        for(int j = 0; j < current_word.length(); j++){
            // Convert character to 0-25 index (e.g., 'a' -> 0, 'b' -> 1)
            int weight_index = current_word[j] - 'a'; 
            
            // Look up the letter's weight directly from the weights array
            sum += weights[weight_index]; 
        }
        
        // Apply modulo 26
        sum %= 26;
        
        // Map to reverse alphabetical order (0 -> 'z', 1 -> 'y', etc.)
        char letter = 'z' - sum;
        
        // Append it right here!
        result += letter;
    }
    
    return result;
    }
};