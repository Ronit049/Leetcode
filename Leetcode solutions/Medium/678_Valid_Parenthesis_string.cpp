// Greedy Keeping track of maximum and minimum possible balancce
class Solution {
public:
    bool checkValidString(string s) {
        int minBalance=0,maxBalance=0;
        for(char &c:s) {
            if(c=='(')
                minBalance++,maxBalance++;
            else if(c==')')
                minBalance-=minBalance>0?1:0,maxBalance--;
            else
                minBalance-=minBalance>0?1:0,maxBalance++;
            if(maxBalance<0)
                return false;
        }
        return minBalance==0;
    }
};