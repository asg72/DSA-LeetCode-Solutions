class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> arrMap;
        unordered_set<int> arrSet;

        for(int num: arr){
            arrMap[num]++;
        }

        for(auto& [key, frequency] : arrMap){
            arrSet.insert(frequency);
        }


        return arrMap.size() == arrSet.size();
    }
};