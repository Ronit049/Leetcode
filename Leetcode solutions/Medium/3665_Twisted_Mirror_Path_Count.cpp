class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const long long MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        // left[i][j]  = ways entering (i,j) from the left
        // above[i][j] = ways entering (i,j) from above
        vector<vector<long long>> left(m, vector<long long>(n, 0));
        vector<vector<long long>> above(m, vector<long long>(n, 0));

        // Start at (0,0)
        // We can initially choose RIGHT or DOWN.
        if (n > 1)
            left[0][1] = 1;

        if (m > 1)
            above[1][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Destination
                if (i == m - 1 && j == n - 1) {
                    return (left[i][j] + above[i][j]) % MOD;
                }

                long long fromL = left[i][j];
                long long fromA = above[i][j];

                if (grid[i][j] == 1) {
                    // Mirror

                    // Entered from left -> turn DOWN
                    if (fromL && i + 1 < m) {
                        above[i + 1][j] =
                            (above[i + 1][j] + fromL) % MOD;
                    }

                    // Entered from above -> turn RIGHT
                    if (fromA && j + 1 < n) {
                        left[i][j + 1] =
                            (left[i][j + 1] + fromA) % MOD;
                    }
                }
                else {
                    // Normal cell

                    long long ways = (fromL + fromA) % MOD;

                    // Move right
                    if (j + 1 < n) {
                        left[i][j + 1] =
                            (left[i][j + 1] + ways) % MOD;
                    }

                    // Move down
                    if (i + 1 < m) {
                        above[i + 1][j] =
                            (above[i + 1][j] + ways) % MOD;
                    }
                }
            }
        }

        return 0;
    }
};