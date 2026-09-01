class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        
        int curr_sum=0;
        for(int i=0; i<k;++i){
            curr_sum+=arr[i];
        }
        
        int max_sum=curr_sum;
        
        for(int right=k; right<n; ++right) {
            int left=right-k;
            
            curr_sum+=arr[right];
            curr_sum-=arr[left];
            
            max_sum=max(max_sum, curr_sum);
        }
        
        return max_sum;
    }
};