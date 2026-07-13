class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        int lowlen = to_string(low).size();
        int highlen = to_string(high).size();

        for(int len = lowlen; len <= highlen; len++){

            for(int start = 1; start <= 10-len; start++){

                int num = 0;
                int curr = start;

                for(int i=0; i<len; i++){
                    num = num * 10 + curr;
                    curr++;
                }

                if(num >= low && num <= high){
                    ans.push_back(num);
                }

            }

        }

        return ans;
    }
};