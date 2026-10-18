class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    vector<vector<long long>> C;

    long long solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return 1;

        vector<int> left, right;

        int root = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long leftWays = solve(left);
        long long rightWays = solve(right);

        // Choose positions for left subtree elements
        // among the remaining n-1 positions.
        long long waysToMerge = C[n - 1][left.size()];

        return waysToMerge * leftWays % MOD * rightWays % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // Pascal's triangle for combinations
        C.assign(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            C[i][0] = C[i][i] = 1;

            for (int j = 1; j < i; j++) {
                C[i][j] =
                    (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        // Subtract the original ordering
        return (solve(nums) - 1 + MOD) % MOD;
    }
};