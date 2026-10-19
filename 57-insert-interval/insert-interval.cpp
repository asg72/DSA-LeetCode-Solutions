class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>>newArr;

        bool inserted = false;
        for(int i=0; i<n; i++){
            if(inserted == false && intervals[i][0] >= newInterval[0]){
                newArr.push_back({newInterval[0], newInterval[1]});
                inserted = true;
            } 

            newArr.push_back({intervals[i][0], intervals[i][1]});
        }

        newArr.push_back({newInterval[0], newInterval[1]}); 

        vector<vector<int>>res;

        int start1 = newArr[0][0];
        int end1 = newArr[0][1];
        for(int i=1; i<newArr.size(); i++){
            int start2 = newArr[i][0];
            int end2 = newArr[i][1];

            if(end1 >= start2){
                end1 = max(end1, end2);
                continue;
            }

            res.push_back({start1, end1});

            start1 = start2;
            end1 = end2;
        }

        res.push_back({start1, end1});


        return res;
    }
};