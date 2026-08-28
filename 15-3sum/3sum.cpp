class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> arr;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    arr.push_back({nums[i], nums[j], nums[k]});

                    j++; k--;

                } else if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                }
            }
        }
        
        sort(arr.begin(), arr.end());
        auto it = unique(arr.begin(), arr.end());

        arr.erase(it, arr.end());
        
        return arr;
    }
};