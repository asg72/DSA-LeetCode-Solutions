class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        auto max_it = max_element (nums.begin(), nums.end());

        int first=*max_it;
        int second=first;

        for(auto num: nums){
            if(num <= first) first = num;
            else if(num<=second && num>first) second=num;
            else if(num>second) return true;
        }

        return false;
    }
};