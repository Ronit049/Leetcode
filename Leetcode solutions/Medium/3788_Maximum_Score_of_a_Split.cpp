class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        
        // suffixMin[i] = min(nums[i+1..n-1]), valid for i = 0..n-2
        vector<long long> suffixMin(n);
        suffixMin[n - 1] = LLONG_MAX; // unused sentinel
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min((long long)nums[i + 1], suffixMin[i + 1]);
        }
        
        long long maxScore = LLONG_MIN;
        long long prefixSum = 0;
        
        for (int i = 0; i < n - 1; i++) {
            prefixSum += nums[i];
            long long score = prefixSum - suffixMin[i];
            maxScore = max(maxScore, score);
        }
        
        return maxScore;
    }
};