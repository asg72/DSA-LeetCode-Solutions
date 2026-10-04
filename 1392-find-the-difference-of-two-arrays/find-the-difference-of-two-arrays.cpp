class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res;

        unordered_set<int> arr1(nums1.begin(), nums1.end());
        unordered_set<int> arr2(nums2.begin(), nums2.end());
        
        nums1 = {};
        nums2 = {};

        for(int num : arr1){
            if(!arr2.contains(num)){
                nums1.push_back(num);
            } 
        }

        for(int num : arr2){
            if(!arr1.contains(num)){
                nums2.push_back(num);
            } 
        }

        res.push_back(nums1);
        res.push_back(nums2);

        return res;
    }
};