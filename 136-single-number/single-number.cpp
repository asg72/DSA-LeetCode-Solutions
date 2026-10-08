class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int val: nums){
            int freq=0;
            for(int el: nums){
                if(el==val){
                    freq++;
                }
            }
            if(freq==1){
                    return val;
                }
            }
            return -1;
        }
};