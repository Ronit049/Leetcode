static int memo[100][100][201];
class Solution {
public:
    bool dp(vector<vector<char>>& grid,int i,int j,int bal) {
        int next=bal+(grid[i][j]=='('?1:-1);
        if(next<0)
            return false;
        if(i==grid.size()-1&&j==grid[0].size()-1)
            return next==0;
        if(memo[i][j][bal]!=-1)
            return memo[i][j][bal];
        if(i==grid.size()-1)
            return memo[i][j][bal]=dp(grid,i,j+1,next);
        if(j==grid[0].size()-1)
            return memo[i][j][bal]=dp(grid,i+1,j,next);
        return memo[i][j][bal]=dp(grid,i+1,j,next)||dp(grid,i,j+1,next);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(memo,-1,sizeof memo);
        return dp(grid,0,0,0);
    }
};