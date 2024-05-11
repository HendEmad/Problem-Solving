class Solution {
public:
    string makeGood(string s) {
        stack<char> st;

        for (char c : s) {
            if (!st.empty() && abs(st.top() - c) == 32) { // Check if characters form a bad pair
                st.pop(); // Pop the top character if it forms a bad pair
            } else {
                st.push(c); // Push the current character onto the stack
            }
        }

        // Construct the resulting string from characters remaining in the stack
        string result;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};