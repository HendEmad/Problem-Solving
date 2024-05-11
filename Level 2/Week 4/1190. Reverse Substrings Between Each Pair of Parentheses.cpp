class Solution {
public:
    string reverseParentheses(string s) {
        stack <char> st;
        string str = "";
        
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                st.push(s[i]);
            if(isalpha(s[i]))
                st.push(s[i]);
            if(s[i] == ')') {
                while(st.top() != '(') {
                    str += st.top();
                    st.pop();
                }
                st.pop();
                for(int i = 0; i < str.length(); i++) {
                    st.push(str[i]);
                }

                str = "";
            }        
        }

        while(!st.empty()) {
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};