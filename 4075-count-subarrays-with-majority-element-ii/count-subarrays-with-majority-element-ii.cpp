class Solution {
private:
    // A standard Fenwick Tree (Binary Indexed Tree) structure
    // It acts as our highly optimized "Tally Sheet"
    class FenwickTree {
    private:
        vector<int> tree;
        int size;

    public:
        FenwickTree(int n) : size(n) {
            tree.assign(n + 1, 0);
        }

        // Add 1 tally mark at a specific index
        void add(int index, int delta) {
            for (; index <= size; index += index & -index) {
                tree[index] += delta;
            }
        }

        // Count how many total tally marks exist from index 1 up to 'index'
        int query(int index) {
            int sum = 0;
            for (; index > 0; index -= index & -index) {
                sum += tree[index];
            }
            return sum;
        }
    };

public:
    long long countMajoritySubarrays(const vector<int>& nums, int target) {
        int n = nums.size();
        long long total_winning_subarrays = 0;
        int current_height = 0;

        // The maximum possible height variation in the worst case is from -n to +n.
        // To avoid negative indices in our Fenwick Tree, we apply an offset shift.
        int offset = n + 1;
        FenwickTree tally_sheet(2 * n + 2);

        // Record our starting ground level (0 + offset) into the tally sheet
        tally_sheet.add(0 + offset, 1);

        for (int num : nums) {
            // 1. Tug-of-War: Update running height balance
            if (num == target) {
                current_height += 1;
            } else {
                current_height -= 1;
            }

            // 2. Query the sheet for all recorded heights strictly less than current_height.
            // In a shifted system, strictly less than (current_height + offset) 
            // means checking everything from index 1 up to (current_height + offset - 1).
            total_winning_subarrays += tally_sheet.query(current_height + offset - 1);

            // 3. Document the new height into our tally sheet for future iterations
            tally_sheet.add(current_height + offset, 1);
        }

        return total_winning_subarrays;
    }
};