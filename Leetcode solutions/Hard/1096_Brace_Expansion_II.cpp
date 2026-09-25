class Solution {
public:
    vector<string> merge(vector<string> &L, vector<string> R)
    {
        if(L.empty())
            return R;
        if(R.empty())
            return L;
        vector<string> result;
        for(string &s1:L)
            for(string &s2:R)
                result.push_back(s1+s2);
        sort(result.begin(),result.end());
        result.resize(unique(result.begin(),result.end())-result.begin());
        return result;
    }
    vector<string> solve(string &ex)
    {
        vector<string> result;
        while(i<ex.length()&&ex[i]!='}'&&ex[i]!=',')
            if(ex[i]=='{')
            {
                i++;
                result=merge(result,braceExpansionII(ex));
                i++;
            }
            else
            {
                string temp;
                while(i<ex.length()&&isalpha(ex[i]))
                    temp+=ex[i++];
                result=merge(result,{temp});
            }
        return result;
    }
    vector<string> braceExpansionII(string expression)
    {
        vector<string> result,temp;
        result=solve(expression);
        while(i<expression.length()&&expression[i]==',')
        {
            i++;
            temp=solve(expression);
            result.insert(result.begin(),temp.begin(),temp.end());
        }
        sort(result.begin(),result.end());
        result.resize(unique(result.begin(),result.end())-result.begin());
        return result;
    }
    private:
    int i=0;
};