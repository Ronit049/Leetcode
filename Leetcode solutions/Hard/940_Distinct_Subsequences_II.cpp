class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        vector<int> last(26, -1); // last[c] = index i (1-indexed) where char last appeared

        dp[0] = 1; // represents the empty subsequence, makes formula clean
        for (int i = 1; i <= n; i++) {
            int c = s[i - 1] - 'a';
            dp[i] = (2 * dp[i - 1]) % MOD;
            if (last[c] != -1) {
                dp[i] = (dp[i] - dp[last[c] - 1] + MOD) % MOD;
            }
            last[c] = i;
        }
        // dp[n] counts all distinct subsequences including empty one -> subtract 1
        return (dp[n] - 1 + MOD) % MOD;
    }
};