class Solution {
public:
    int m;
    int n;

    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> que;

        que.push({i, j});
        grid[i][j] = '$';

        while (!que.empty()) {
            auto it = que.front();
            que.pop();

            for (auto &dir : directions) {
                int i_ = it.first + dir[0];
                int j_ = it.second + dir[1];

                if (i_ < 0 || i_ >= m || j_ < 0 || j_ >= n ||
                    grid[i_][j_] != '1') {
                    continue;
                }
                else {
                    que.push({i_, j_});
                    grid[i_][j_] = '$';
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    islands++;
                }
            }
        }

        return islands;
    }
};