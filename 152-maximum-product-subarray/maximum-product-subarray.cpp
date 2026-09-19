class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxEndin = nums[0];
        int minEndin = nums[0];
        int res = nums[0];

        for(int i=1; i<nums.size(); i++){
            int v1 = nums[i];
            int v2 = maxEndin * nums[i];
            int v3 = minEndin * nums[i];

            maxEndin = max(v1, max(v3, v2));
            minEndin = min(v1, min(v2, v3));
            
            res = max(res, max(maxEndin, minEndin));
        }

        return res;
    }
};