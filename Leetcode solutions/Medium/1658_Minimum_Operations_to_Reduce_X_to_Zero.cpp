class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=accumulate(nums.begin(),nums.end(),0)-x;
        if(sum<0)
            return -1;
        int result=nums.size()+1,start=0;
        for(int i=0;i<nums.size();i++)
        {
            sum-=nums[i];
            while(sum<0)
                sum+=nums[start++];
            if(!sum)
                result=min(result,(int)nums.size()-i+start-1);
        }
        return result==nums.size()+1?-1:result;
    }
};