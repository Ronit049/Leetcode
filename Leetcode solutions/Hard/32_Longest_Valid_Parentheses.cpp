class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<int,char>> st;
        int result=0;
        st.push({0,'x'});
        for(char &c:s) {
            if(c=='(')
                st.push({0,c});
            else {
                if(!st.empty()) {
                    if(st.top().second=='(') {
                        int count=st.top().first+2;
                        st.pop();
                        st.top().first+=count;
                        result=max(result,st.top().first);
                    } else {
                        st=stack<pair<int,char>>();
                        st.push({0,'x'});
                    }
                }
            }
        }
        return result;
    }
};