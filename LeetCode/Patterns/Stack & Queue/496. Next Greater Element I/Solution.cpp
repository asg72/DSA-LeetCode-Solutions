class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> m;
        vector<int> res;

        for(int i=0; i<nums2.size(); i++){
            if(st.empty()){
                st.push(nums2[i]);
            }

            if(nums2[i] > st.top()){
                m[st.top()] = nums2[i];
                st.pop();
                st.push(nums2[i]);
            }
        }

        for(int i=0; i<nums1.size(); i++){
            if(m.contains(nums1[i])){
                res.push_back(m[nums1[i]]);
            } else{
                res.push_back(-1);
            }

        }

        return res;
    }
};