class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length()>k) {
            string nS;
            for(int i=0;i<s.length();i+=k) {
                int next=0;
                for(int j=i;j<s.length()&&j<i+k;j++)
                    next+=s[j]-'0';
                nS+=to_string(next);
            }
            nS.swap(s);
        }
        return s;
    }
};