class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> res;

        int s=1;
        while(s<=A.size()){
            int c=0;

            for(int i=0; i<s; i++){
                for(int j=0; j<s; j++){
                    if(A[i]==B[j]){
                        c++;
                    }
                }
            }

            res.push_back(c);
            s++;
        }
        return res;
    }
};