class Solution {
public:
    vector<string> result;
    void dfs(string s,int left,int right,int open,int start)
    {
        for(int i=start;i<s.length()&&open>=0;i++)
        {
            if(s[i]=='(')
            {
                if(left>0&&(i==0||s[i-1]!='('))
                    dfs(s.substr(0,i)+s.substr(i+1),left-1,right,open,i);
                open++;
            }
            else if(s[i]==')')
            {
                if(right>0&&(i==0||s[i-1]!=')'))
                    dfs(s.substr(0,i)+s.substr(i+1),left,right-1,open,i);
                open--;
            }   
        }
        if(open==0&&left==0&&right==0)
            result.push_back(s);
    }
    vector<string> removeInvalidParentheses(string s) 
    {
        if(s.empty())
            return {""};
        int left=0,right=0;
        for(char &c:s)
            if(c=='(')
                left++;
            else if(c==')')
                if(left>0)
                    left--;
                else
                    right++;
        if(left==0&&right==0)
            return {s};
        dfs(s,left,right,0,0);
        return result;
    }
};