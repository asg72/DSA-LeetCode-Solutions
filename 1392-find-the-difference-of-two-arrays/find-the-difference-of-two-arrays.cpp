class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

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

        return {nums1, nums2};
    }
};