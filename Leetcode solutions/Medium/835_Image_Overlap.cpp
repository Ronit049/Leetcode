class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        const int n = img1.size();
        int r = 0;
        for (int x = 1 - n; x < n; ++x) {
            for (int y = 1 - n; y < n; ++y) {
                int may = 0;
                // a + x >= 0, a + x < n a >= 0 a < n
                for (int a = max(-x, 0); a + x < n && a < n; ++a) {
                    for (int b = max(-y, 0); b + y < n && b < n; ++b) {
                        if (img1[a][b] && img1[a][b] == img2[a + x][b + y]) {
                            ++may;
                        }
                    }
                }
                r = max(r, may);
            }

        }
        return r;
        
    }
};