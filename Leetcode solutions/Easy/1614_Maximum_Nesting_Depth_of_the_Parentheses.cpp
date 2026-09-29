class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int result=0;
        for(char &c:s) {
            if(c=='(')
                st.push(c);
            else if(c==')')
                st.pop();
            result=max(result,(int)st.size());
        }
        return result;
    }
};