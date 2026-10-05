class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int result=0;
        for(char &c:s)
            if(c=='(')
                st.push(0);
            else {
                int curr=0;
                while(st.top()!=0) {
                    curr+=st.top();
                    st.pop();
                }
                st.top()={max(1,curr*2)};
            }
        while(!st.empty())
            result+=st.top(),st.pop();
        return result;
    }
};