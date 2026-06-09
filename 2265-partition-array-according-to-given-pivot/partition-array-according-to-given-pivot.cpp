class Solution {
public:
    vector<int> pivotArray(vector<int>& arr, int p) {
        int n = arr.size();
        vector<int> ans;
        ans.reserve(n);

        int c=0;

        for(int i=0; i<n; i++){
            if(arr[i]<p){
                ans.push_back(arr[i]);
            } else if(arr[i] == p){
                c++;
            }
        }
        for(int i=0; i<c; i++){
            ans.push_back(p);
        }

        for(int i=0; i<n; i++){
            if(arr[i]>p){
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};