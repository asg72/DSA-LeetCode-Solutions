class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        // Sort balloons by their end coordinate
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int last_end = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            // If current balloon starts after the last arrow position, shoot a new arrow
            if (points[i][0] > last_end) {
                arrows++;
                last_end = points[i][1];
            }
        }

        return arrows;
    }
};