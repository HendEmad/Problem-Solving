class Solution {
public:
    int scoreOfParentheses(string s) {
    stack<int> st;
    int currentScore = 0;

    for (char c : s) {
        if (c == '(') {
            st.push(currentScore);
            currentScore = 0;
        } else {
            currentScore = st.top() + max(2 * currentScore, 1);
            st.pop();
        }
    }

    return currentScore;
    }
};