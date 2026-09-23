class Solution {
public:
    int maxAbsoluteSum(vector<int>& arr) {
        int minEnding = arr[0];
        int maxEnding = arr[0];
        int minRes = arr[0];
        int maxRes = arr[0];
        

        for (int i = 1; i < arr.size(); i++) {
            int v1 = arr[i];
            int v2Max = arr[i] + maxEnding;
            int v2Min = arr[i] + minEnding;

            minEnding = min(v1, v2Min);
            maxEnding = max(v1, v2Max);

            minRes = min(minRes, minEnding);
            maxRes = max(maxRes, maxEnding);
        }

        int maxAbsSum = max(maxRes, abs(minRes));

        return maxAbsSum;
    }
};