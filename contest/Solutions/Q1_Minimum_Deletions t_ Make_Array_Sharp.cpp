class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int deletions = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                deletions++;
            }
        }

        return deletions;
    }
};