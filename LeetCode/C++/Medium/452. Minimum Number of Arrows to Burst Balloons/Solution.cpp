class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();

        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        if (n == 1) {
            return 1;
        } else if (n == 0) {
            return 0;
        }

        int arrow = 1;
        int end1 = points[0][1];

        for (int i = 1; i < n; i++) {
            int st2 = points[i][0];
            int end2 = points[i][1];

            if (end1 >= st2) {
                end1 = min(end1, end2);
            } else {
                end1 = end2;
                arrow++;
            }
        }

        return arrow;
    }
};