class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();

        if(n < k) return -1;

        bool is_vowel[256] = {false};
        is_vowel['a'] = is_vowel['e'] = is_vowel['i'] = is_vowel['o'] = is_vowel['u'] = true;

        int curVow=0;
        for(int i=0; i<k; ++i){
            if(is_vowel[static_cast<unsigned char>(s[i])]){
                curVow++;
            }
        }

        int maxVow = curVow;
        for(int right=k; right<n; ++right){
            int left = right-k;

            if(is_vowel[static_cast<unsigned char>(s[right])]) curVow++;

            if(is_vowel[static_cast<unsigned char>(s[left])]) curVow--;

            maxVow = max(maxVow, curVow);
        }

        return maxVow;
    }
};