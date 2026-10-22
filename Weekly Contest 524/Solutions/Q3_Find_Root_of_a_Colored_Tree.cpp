class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();

        vector<int> indegree(n, 0);
        vector<int> degree(n, 0);

        auto nextColor = [](char c) {
            if (c == 'R') return 'B';
            if (c == 'B') return 'W';
            return 'R';
        };

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            degree[u]++;
            degree[v]++;

            // u -> v
            if (colors[v] == nextColor(colors[u])) {
                indegree[v]++;
            }
            // v -> u
            else if (colors[u] == nextColor(colors[v])) {
                indegree[u]++;
            }
            // Same color or invalid color transition
            else {
                return -1;
            }
        }

        int root = -1;

        for (int i = 0; i < n; i++) {
            // Root must have at most 2 children
            if (indegree[i] == 0) {
                if (degree[i] > 2)
                    continue;

                if (root != -1)
                    return -1; // More than one possible root

                root = i;
            }
        }

        return root;
    }
};