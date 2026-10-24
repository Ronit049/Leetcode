class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        vector<int> vornelqixa = nums;

        long long ans = 0;
        int lastBad = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                lastBad = i;
            }

            // Every subarray starting after lastBad is valid
            ans += i - lastBad;
        }

        return ans;
    }
};