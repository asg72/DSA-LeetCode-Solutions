class Solution {
public:
    vector<int> arrayRankTransform(std::vector<int>& arr) {
        // Create a copy of the array to sort
        vector<int> sorted_arr(arr);
        sort(sorted_arr.begin(), sorted_arr.end());

        unordered_map<int, int> rank;
        int current_rank = 1;

        // Assign ranks to unique elements
        for (int num : sorted_arr) {
            if (rank.find(num) == rank.end()) {
                rank[num] = current_rank;
                current_rank++;
            }
        }

        // Replace original elements with their calculated ranks
        for (size_t i = 0; i < arr.size(); i++) {
            arr[i] = rank[arr[i]];
        }

        return arr;
    }
};