class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> f;

        int low = 0;
        int high = 0;

        int max_len = 0;

        while (high < n) {
            f[arr[high]]++;

            while (f.size() > 2) {
                f[arr[low]]--;
                if (f[arr[low]] == 0) {
                    f.erase(arr[low]);
                }
                low++;
            }

            if (f.size() <= 2) {
                int len = high - low + 1;
                max_len = max(max_len, len);
            }

            high++;
        }
        
        return max_len;
    }
};