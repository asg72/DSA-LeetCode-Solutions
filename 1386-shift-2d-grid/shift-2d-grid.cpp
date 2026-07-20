class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();    // Number of rows
        int n = grid[0].size(); // Number of columns

        vector<vector<int>> result(m, vector<int>(n));

        // Total elements in the grid
        int totalElements = m * n;
        k = k % totalElements;  // Optimize k to prevent redundant full rotations

        for(int i=0; i<m; i++){
            
            for(int j=0; j<n; j++){
                // Formula to calculate the new 1D position and map it back to 2D
                int oldIdx = i * n + j;
                int newIdx = (oldIdx + k) % totalElements;

                int newRow = newIdx / n;
                int newCol = newIdx % n;

                result[newRow][newCol] = grid[i][j];

            }
        }

        return result;
    }
};