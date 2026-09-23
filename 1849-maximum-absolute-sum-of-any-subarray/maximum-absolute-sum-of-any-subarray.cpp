class Solution {
public:
    int maxSum(vector<int>& arr){
        int bestEnding = arr[0];
        int res = arr[0];

        for(int i=1; i<arr.size(); i++){
            int v1 = arr[i];
            int v2 = arr[i] + bestEnding;

            bestEnding = max(v1, v2);
            res = max(res, bestEnding);
        }

        return res;
    }

    int minSum(vector<int>& arr){
        int bestEnding = arr[0];
        int res = arr[0];

        for(int i=1; i<arr.size(); i++){
            int v1 = arr[i];
            int v2 = arr[i] + bestEnding;

            bestEnding = min(v1, v2);
            res = min(res, bestEnding);
        }

        return res;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        int max_Sum = maxSum(nums);
        int min_Sum = minSum(nums);

        int maxAbsSum = max(max_Sum, abs(min_Sum));

        return maxAbsSum;
    }
};