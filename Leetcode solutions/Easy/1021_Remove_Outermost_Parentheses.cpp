class Solution {
public:
    string removeOuterParentheses(string S) 
    {
        int open=0,start=0;
        string result;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='(')
                open++;
            else
                open--;
            if(open==0)
                result+=S.substr(start+1,i-start-1),start=i+1;
        }
        return result;
    }
};