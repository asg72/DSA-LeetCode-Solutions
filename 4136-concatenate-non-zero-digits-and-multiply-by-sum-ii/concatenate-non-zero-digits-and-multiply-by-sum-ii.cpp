class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;

        // 1. Precompute structures matching the original string size
        vector<long long> prefSum(m + 1, 0);
        vector<long long> prefX(m + 1, 0);
        vector<long long> pow10(m + 1, 1);
        vector<int> cntNonZero(m + 1, 0); // Tracks how many non-zeros up to index i

        for (int i = 0; i < m; ++i) {
            int digit = s[i] - '0';
            
            if (digit != 0) {
                prefSum[i + 1] = prefSum[i] + digit;
                prefX[i + 1] = (prefX[i] * 10 + digit) % MOD;
                cntNonZero[i + 1] = cntNonZero[i] + 1;
            } else {
                // If it's a zero, it adds nothing to sum, doesn't shift the number x, 
                // and keeps the non-zero count the same.
                prefSum[i + 1] = prefSum[i];
                prefX[i + 1] = prefX[i];
                cntNonZero[i + 1] = cntNonZero[i];
            }
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }

        // 2. Build 'next non-zero' pointer to skip zeros at the start of a query
        vector<int> nxt(m, -1);
        int last = -1;
        for (int i = m - 1; i >= 0; --i) {
            if (s[i] != '0') last = i;
            nxt[i] = last;
        }

        // 3. Process Queries in O(1) time
        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];

            // Find the actual first non-zero digit position in [l, r]
            int first_nonzero = nxt[l];
            
            // If there are no non-zeros or the next one is past our right boundary 'r'
            if (first_nonzero == -1 || first_nonzero > r) {
                answer.push_back(0);
                continue;
            }

            // Total active non-zero digits in this substring range
            int digits_count = cntNonZero[r + 1] - cntNonZero[first_nonzero];

            // Extract math equations
            long long digitSum = prefSum[r + 1] - prefSum[first_nonzero];
            long long x = (prefX[r + 1] - (prefX[first_nonzero] * pow10[digits_count]) % MOD + MOD) % MOD;

            long long res = (x * digitSum) % MOD;
            answer.push_back(res);
        }

        return answer;
    }
};