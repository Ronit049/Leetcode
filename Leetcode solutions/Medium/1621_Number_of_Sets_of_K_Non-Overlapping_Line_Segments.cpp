static int MOD=1e9+7;
static int memo[1001][1001];
class Solution {
public:
    int n;
    int dp(int k,int end)
    {
        if(k==0)
            return 1;
        if(memo[k][end]!=-1)
            return memo[k][end];
        memo[k][end]=0;
        for(int j=end+1;j<n-k+1;j++)
            memo[k][end]=(memo[k][end]+((long)(j-end)*dp(k-1,j))%MOD)%MOD;
        return memo[k][end];
    }
    int numberOfSets(int n, int k) 
    {
        memset(memo,-1,sizeof memo);
        this->n=n;
        return dp(k,0);
    }
};