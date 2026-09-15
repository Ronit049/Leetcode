class Solution {
public:
    vector<vector<bool>> pal;
    int k;
    void isPal(string &s,int i,int j) {
        for(;i>=0&&j<s.length();i--,j++)
            if(s[i]==s[j])
                pal[i][j]=true;
            else
                return;
    }
    vector<int> memo;
    int dp(string &s,int i) {
        if(i==s.length())
            return 0;
        if(memo[i]!=-1)
            return memo[i];
        int result=dp(s,i+1);
        for(int j=i;j<s.length();j++)
            if(pal[i][j]&&j-i+1>=k) 
                result=max(result,1+dp(s,j+1));
        return memo[i]=result;
    }
    int maxPalindromes(string s, int k) {
        this->k=k;
        pal.resize(s.size(),vector<bool>(s.size(),false));
        for(int i=0;i<s.length();i++) {
            isPal(s,i,i);
            if(i>0)
                isPal(s,i-1,i);
        }
        memo.resize(s.length(),-1);
        return dp(s,0);
    }
};