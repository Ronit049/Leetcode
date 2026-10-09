class Solution {
public:
    int minInsertions(string s) 
    {
        int r=0,result=0;
        for(char &c:s)
        {
            if(c==')')
            {
                r--;
                if(r<0)
                    result++,r+=2;
            }
            else
            {
                if(r%2)
                    r--,result++;
                r+=2;
            }
        }
        return result+r;
    }
};