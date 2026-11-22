class Solution {
public:
    bool checkString(string s) {
        bool gotB=false;
        for(char &c:s) {
            if(c=='b')
                gotB=true;
            else if(gotB)
                return false;
        }
        return true;
    }
};