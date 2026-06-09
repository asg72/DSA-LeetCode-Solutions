class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        // Find both min and max iterators in a single pass
        auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
        
        // Cast to long long before multiplying to prevent integer overflow
        return static_cast<long long>(*max_it - *min_it) * k;
    }
};