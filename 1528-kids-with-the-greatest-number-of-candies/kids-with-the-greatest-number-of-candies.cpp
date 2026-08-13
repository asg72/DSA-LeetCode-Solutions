class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candie = ranges::max(candies);
        
        vector<bool> res;
        for(auto num : candies){
            if((num+extraCandies) >= max_candie){
                res.push_back(1);
            } else{
                res.push_back(0);
            }
        }

        return res;
    }
};