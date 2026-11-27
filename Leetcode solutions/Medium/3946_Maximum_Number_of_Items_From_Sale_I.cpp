static int memo[1001][1501][2];
class Solution {
public:
    vector<int> factorCount;
    int dp(vector<vector<int>>& items,int start,int budget,bool take) {
        if(start==items.size())
            return 0;
        if(memo[start][budget][take]!=-1)
            return memo[start][budget][take];
        int result=dp(items,start+1,budget,true);
        if(items[start][1]<=budget)
            result=max(result,1+take*factorCount[start]+dp(items,start,budget-items[start][1],false));
        return memo[start][budget][take]=result;
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        factorCount.resize(items.size(),0);
        memset(memo,-1,sizeof memo);
        for(int i=0;i<items.size();i++)
            for(int j=0;j<items.size();j++)
                if(i!=j)
                    factorCount[i]+=items[j][0]%items[i][0]==0;
        return dp(items,0,budget,true);
    }
};