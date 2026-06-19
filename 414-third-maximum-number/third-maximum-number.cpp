class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<long long> MAX(3,LLONG_MIN);
        for (int i=0;i<nums.size();i++){
            if(MAX[2] == nums[i] || MAX[1] == nums[i]|| MAX[0] == nums[i]) continue;
            if(nums[i]>MAX[0]){
                MAX[2]=MAX[1];MAX[1]=MAX[0];MAX[0]=nums[i];
            }else if(nums[i]>MAX[1]){
                MAX[2]=MAX[1];MAX[1]=nums[i];
            }else if(nums[i]>MAX[2]){
                MAX[2]=nums[i];
            }
        }
        return MAX[2] == LLONG_MIN ? MAX[0] : MAX[2];
    }
};