class Solution {
public:
    int minMoves(vector<int>& nums) {
        int result=0;
        sort(nums.rbegin(),nums.rend());
        for(int i=1;i<nums.size();i++)
            result+=nums[i-1]-nums[i],nums[i]=nums[i-1];
        return result;
    }
};