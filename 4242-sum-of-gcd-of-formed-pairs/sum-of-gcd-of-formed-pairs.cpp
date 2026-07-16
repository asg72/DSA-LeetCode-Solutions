class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prefixGcd;
        int runin_max = 0;

        for(int i=0; i<n; i++){
            runin_max = max(runin_max,nums[i]);
            prefixGcd.push_back(gcd(nums[i], runin_max));
        }

        sort(prefixGcd.begin(), prefixGcd.end());
        
        long long ans=0;
        int st=0, end=n-1;

        while(st < end){
            ans += gcd(prefixGcd[st], prefixGcd[end]);
            st++; end--;
        }

        return ans;
    }
};