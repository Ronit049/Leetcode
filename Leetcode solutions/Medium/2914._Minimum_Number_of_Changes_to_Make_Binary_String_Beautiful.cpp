class Solution {
public:
    int minChanges(string s) {
        int oneCount=0,zeroCount=0,result=0;
        for(int i=0,start=0;i<s.size();i++) {
            oneCount+=s[i]=='1';
            zeroCount+=s[i]=='0';
            if(i-start+1==2) {
                result+=min(2-oneCount,2-zeroCount);
                start=i+1;
                oneCount=0;
                zeroCount=0;
            }
        }
        return result;
    }
};