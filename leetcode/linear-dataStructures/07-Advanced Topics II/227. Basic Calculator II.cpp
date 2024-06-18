class Solution {
public:
    int calculate(string s) {
        stack<int> operands;
        int num = 0;
        char sign = '+';

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if ((!isdigit(c) && c != ' ') || i == s.length() - 1) {
                if (sign == '+') {
                    operands.push(num);
                } else if (sign == '-') {
                    operands.push(-num);
                } else if (sign == '*') {
                    int prev = operands.top();
                    operands.pop();
                    operands.push(prev * num);
                } else if (sign == '/') {
                    int prev = operands.top();
                    operands.pop();
                    operands.push(prev / num);
                }
                sign = c;
                num = 0;
            }
        }
        
        int result = 0;
        while (!operands.empty()) {
            result += operands.top();
            operands.pop();
        }
        
        return result;
    }
};