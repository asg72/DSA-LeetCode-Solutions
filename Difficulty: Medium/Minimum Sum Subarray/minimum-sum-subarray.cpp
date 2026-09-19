class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        // code here
        int bestEndin=arr[0];
        int res=arr[0];
        
        for(int i=1; i<arr.size();i++){
            int v1=arr[i];
            int v2=arr[i] + bestEndin;
            
            bestEndin = min(v1, v2);
            res = min(res, bestEndin);
        }
        
        return res;
    }
};