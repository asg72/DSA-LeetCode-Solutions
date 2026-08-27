class Solution {
public:
    vector<int> twoSum(vector<int>& num, int tar) {
        vector<int> idxs;

        int n=num.size();

        int st=0;
        int end=n-1;
        while(st<end){
            int sum = num[st]+num[end];
            if(sum == tar){
                idxs.push_back(st+1);
                idxs.push_back(end+1);
                break;
            } else if(sum>tar){
                end--;
            } else{
                st++;
            }
        }
        return idxs;
    }
};