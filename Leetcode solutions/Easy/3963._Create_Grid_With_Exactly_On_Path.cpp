class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        // First row is free
        for (int j = 0; j < n; j++) {
            grid[0][j] = '.';
        }

        // Last column is free
        for (int i = 0; i < m; i++) {
            grid[i][n - 1] = '.';
        }

        return grid;
    }
};