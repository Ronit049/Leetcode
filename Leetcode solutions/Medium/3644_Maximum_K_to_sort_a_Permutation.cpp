class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end()))
            return 0;
        int result=0xFFFFFFFFF;
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=i)
                result&=nums[i];
        return result;
    }
};