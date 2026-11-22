class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        int result=0;
        for(int i=0;i<nums.size();i++)
            if(i==0)
                result+=nums[i+1]<=nums[i];
            else if(i+1==nums.size())
                result+=nums[i-1]<=nums[i];
            else
                result+=((nums[i-1]+nums[i+1])/2.0)<=nums[i];
        return result;
    }
};