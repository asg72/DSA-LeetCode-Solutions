class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int st=nums[0];

        vector<int> ans;
        
        for(int num: nums){
           while(st < num){
            ans.push_back(st);
            st++;
           }
           st = num + 1;
        }

    return ans;
    }

};