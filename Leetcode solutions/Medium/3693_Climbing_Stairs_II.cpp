class Solution {
public:
    vector<int> memo;
    int dp(vector<int>& costs,int start) {
        if(start==costs.size()-1)
            return 0;
        if(memo[start+1]!=-1)
            return memo[start+1];
        int result=INT_MAX;
        if(start+1<costs.size())
            result=costs[start+1]+1+dp(costs,start+1);
        if(start+2<costs.size())
            result=min(result,costs[start+2]+4+dp(costs,start+2));
        if(start+3<costs.size())
            result=min(result,costs[start+3]+9+dp(costs,start+3));
        return memo[start+1]=result;            
    }
    int climbStairs(int n, vector<int>& costs) {
        memo.resize(n+1,-1);
        return dp(costs,-1);
    }
};