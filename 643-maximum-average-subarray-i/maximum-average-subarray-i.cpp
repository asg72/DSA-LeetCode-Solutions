class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        
        if(n<k) return -1;
        
        double currSum=0;
        for(int i = 0; i<k; ++i){
            currSum+=nums[i];
        }

        double maxAvg=currSum/k;

        for(int right=k; right<n; ++right){
            int left = right-k;

            currSum+=nums[right];
            currSum-=nums[left];
             
            maxAvg=max(currSum/k,maxAvg);
        }

        return maxAvg;
    }
};