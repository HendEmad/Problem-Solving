class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack <int> temp;
        int i = 0, j = 0;
        while(i < pushed.size()) {
            temp.push(pushed[i]);
            while (!temp.empty() && j < popped.size() && popped[j] == temp.top()) {
                temp.pop();
                j++;
            }
            i++;
        }
        return temp.empty() ? true : false;
    }
};