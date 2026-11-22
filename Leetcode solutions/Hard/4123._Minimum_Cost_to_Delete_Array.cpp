class Solution {
public:
    long long minCost(vector<int>& nums) {
        vector<long> memo(2,LLONG_MAX/4);
        memo[0]=0;
        memo[1]=LLONG_MAX/4;
        long mini=LLONG_MAX/4;
        for(int i=1;i+1<nums.size();i++) {
            long a=min(memo[0],memo[1]+nums[i]);
            long b=min(memo[1],memo[0]+nums[i]);
            memo[0]=a,memo[1]=b;
        }
        return memo[0]+nums.back()+nums.front();
    }
};