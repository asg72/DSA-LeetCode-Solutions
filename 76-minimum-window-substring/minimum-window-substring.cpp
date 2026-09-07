class Solution {
public:
    bool isTrue(vector<int> &have , vector<int> &need){
        for(int i=0; i<256; i++){
            if(have[i] < need[i]){
                return false;
            }
        }    
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int>need(256, 0);
        vector<int>have(256, 0);
        
        for(int i=0; i<m; i++){
            need[t[i]]++;
        }
        
        if(n < m) return "";

        int high = 0, low = 0, res = INT_MAX, start = -1;

        while(high < n){
            have[s[high]]++;
            
            while(isTrue(have, need)){
                int len = high - low + 1;
                if(res > len){
                    res = len;
                    start = low;
                }
                have[s[low]]--;
                low++;
            }

            high++;
        }

        if(res == INT_MAX)  return "";

        return s.substr(start, res);
    }
};