class Solution {
public:
    vector<long> memo;
    long long dp(vector<int>& nums,int start) {
        if(start==nums.size())
            return 0;
        if(memo[start]!=LONG_MIN)
            return memo[start];
        long long result=0;
        if(start+2<=nums.size()) {
            long sum=nums[start]+nums[start+1];
            result=sum+(sum%3==0?-dp(nums,start+2):dp(nums,start+2));
        }
        result=max(result,nums[start]+(nums[start]%3==0?-dp(nums,start+1):dp(nums,start+1)));
        return memo[start]=result;
    }
    long long maxDifference(vector<int>& nums) {
        memo.resize(nums.size(),LONG_MIN);
        return dp(nums,0);
    }
};