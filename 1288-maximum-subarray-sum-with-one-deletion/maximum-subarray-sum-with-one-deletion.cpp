class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDelete = arr[0];
        int oneDelete = 0;
        int res = arr[0];

        for(int i=1; i<arr.size(); i++){
            int prevNoDelete = noDelete;
            int v1 = arr[i];
            int v2 = arr[i] + noDelete;

            noDelete = max(v1, v2);
            oneDelete = max(prevNoDelete, oneDelete + v1);
            res = max(res, max(noDelete, oneDelete));
        }

        return res;
    }
};