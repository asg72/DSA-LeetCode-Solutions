class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        f[0] = -1;
        int prefixSum = 0;

        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];
            int rem = prefixSum % k;

            if(f.contains(rem)){
                if(i - (f[rem]) >= 2){
                    return true;
                }
            } else{
                f[rem] = i;
            }
        }

        return false;
    }
};