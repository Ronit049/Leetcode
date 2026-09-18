//Greedy, get all intervals, if there is a valid interval within larger nterval we ignore larger intverval.
class Solution {
public:
    vector<int> left,right;
    int getRight(string &s,int i)
    {
        int r=right[s[i]-'a'];
        for(int j=i;j<=r;j++) 
        {
            if(left[s[j]-'a']<i)
                return -1;
            r=max(r,right[s[j]-'a']);
        }
        return r;
    }
    vector<string> maxNumOfSubstrings(string s) 
    {
        left.resize(26,-1),right.resize(26,-1);
        for(int i=0;i<s.length();i++)
        {
            if(left[s[i]-'a']==-1)
                left[s[i]-'a']=i;
            right[s[i]-'a']=i;
        }
        vector<string> result;
        int r=-1;
        for (int i=0;i<s.length();i++) 
        {
            if(i==left[s[i] - 'a']) 
            {
                int newR=getRight(s,i);
                if(newR!=-1)
                {
                    if(i>r)
                        result.push_back("");                     
                    r=newR;
                    result.back()=s.substr(i,r-i+1);
                }
            }
        }
        return result;
    }
};