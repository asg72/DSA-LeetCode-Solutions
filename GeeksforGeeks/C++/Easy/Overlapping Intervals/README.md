# 📝 Overlapping Intervals (GeeksforGeeks)

🔗 [Problem Link](https://www.geeksforgeeks.org/problems/overlapping-intervals--174556/1)

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen) ![Language](https://img.shields.io/badge/Language-C++-blue)

### 💡 Tags
Sorting

### 🚀 Performance
- **Runtime:** Successfully Evaluated
- **Memory:** N/A

---

### 📜 Problem Description

You are given a 2D array  **arr[][]** which represents a set of intervals, where each element arr[i] = [start, end] defines an interval. 
Your task is to determine if any two intervals in the given set overlap.

**Note:**  Two intervals [a, b] and [c, d] overlap if they have at least one common value, i.e., a ≤ d and c ≤ b.

**Examples:**

```
Input: n = 4, arr[][] = [[1, 3], [5, 7], [2, 4], [6, 8]]
Output: true
Explanation: The intervals [1, 3] and [2, 4] overlap.
```

```
Input: n = 4, arr[][] = [[1, 3], [7, 9], [4, 6], [10, 13]]
Output: false
Explanation: No pair of intervals overlap.
```

**Constraints:** 1 ≤ arr[i][0] < arr[i][1] ≤ 105  
2 ≤ arr.size() ≤ 105