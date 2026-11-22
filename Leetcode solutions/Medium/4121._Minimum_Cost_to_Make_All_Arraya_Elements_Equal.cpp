class Solution {
public:
    long long minCost(vector<int>& nums) {
        long long result=LLONG_MAX;
        for(int i=0;i<nums.size();) {
            int count=1;
            while(i+count<nums.size()&&nums[i]==nums[i+count])
                count++;
            if(i+2<=nums.size()&&i+count>1)
                result=min(result,1LL*nums[i]*((int)nums.size()-count));
            i+=count;
        }
        return result;
    }
};