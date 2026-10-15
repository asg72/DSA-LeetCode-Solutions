class Solution {
public:

    int atMost(vector<int>& nums, int goal){
        int n = nums.size();

        int low = 0, high = 0, res = 0, sum = 0;

        while(high < n){
            sum += nums[high];

            while(sum > goal && low <= high){
                sum -= nums[low];
                low++;
            }

            res += high - low + 1;

            high++;
        }

        return res;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return atMost(nums, goal) - atMost(nums, goal-1);
    }

    
};