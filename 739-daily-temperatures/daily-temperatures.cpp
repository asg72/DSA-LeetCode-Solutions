class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 0);
        stack<int> st;

        // Traverse right-to-left from the very last element
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements that are colder than or equal to the current
            // temperature
            while (!st.empty() && arr[i] >= arr[st.top()]) {
                st.pop();
            }

            // If the stack is not empty, the top element is the next warmer day
            if (!st.empty()) {
                res[i] = st.top() - i;
            }

            // Push the current day's index onto the stack
            st.push(i);
        }

        return res;
    }
};
