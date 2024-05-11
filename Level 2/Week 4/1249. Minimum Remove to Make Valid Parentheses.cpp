class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack <int> st;
        vector <bool> is_removal(s.size(), false);
        string valid = "";

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')') {
                if(st.empty())
                    is_removal[i] = true;
                else
                    st.pop();
            }
        }

        while(!st.empty()) {
            is_removal[st.top()] = true;
            st.pop();
        }

        for(int i = 0; i < s.size(); i++) {
            if(!is_removal[i])
                valid += s[i];
        }

        return valid;
    }
};