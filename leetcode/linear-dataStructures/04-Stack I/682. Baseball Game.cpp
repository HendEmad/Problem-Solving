class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        int totalScore = 0;

        for (const string& op : operations) {
            if (op == "+") {
                int top = scores.top();
                scores.pop();
                int newTop = top + scores.top();
                scores.push(top);
                scores.push(newTop);
            } else if (op == "D") {
                scores.push(2 * scores.top());
            } else if (op == "C") {
                scores.pop();
            } else {
                scores.push(stoi(op));
            }
        }

        // Calculate total score
        while (!scores.empty()) {
            totalScore += scores.top();
            scores.pop();
        }

        return totalScore;
    }
};