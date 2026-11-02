class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int result=0;
        for(int i=0;i<nums.size();i++)
            result+=abs(nums[i]-nums[nums.size()/2]);
        return result;
    }
};