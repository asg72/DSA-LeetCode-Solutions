class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        if(nums.empty()) return 0;

        int st = 0;
        int end = nums.size()-1;
        int pair = 0;
        sort(nums.begin(), nums.end());
        while(st < end){
            int sum = nums[st] + nums[end];

            if(sum == k){
                st++; end--;
                pair++;
            }
            else if(sum < k){
                st++;
            } 
            else{
                end--;
            }
        }

        return pair;
    }
};