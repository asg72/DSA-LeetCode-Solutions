class Solution {
public:
    int maxSum(vector<int>& arr){
        int bestEnding = arr[0];
        int res = arr[0];

        for(int i=1; i<arr.size(); i++){
            int v1 = arr[i];
            int v2 = arr[i] + bestEnding;
        
            bestEnding = max(v1,v2);
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
        
            bestEnding = min(v1,v2);
            res = min(res, bestEnding);
        }
        
        return res;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int a1 = maxSum(nums);
        int a2 = minSum(nums);
        int totalSum = 0;

        for(int i=0; i<nums.size(); i++){
            totalSum += nums[i];
        }

        if(a1 < 0){
            a2 = totalSum + a2;
            
        }else a2 = totalSum - a2;

        return max(a1, a2);
    }
};