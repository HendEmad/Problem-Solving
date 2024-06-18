class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> execution_times(n, 0);
        stack<int> call_stack;
        int prev_start_time = 0;

        for(const string& log: logs) {
            stringstream ss(log);
            string token;
            vector<string> tokens;

            while(getline(ss, token, ':')) {
                tokens.push_back(token);
            }

            int func_id = stoi(tokens[0]);
            string call_type = tokens[1];
            int timestamp = stoi(tokens[2]);

            if(call_type == "start") {
                if(!call_stack.empty()) {
                    execution_times[call_stack.top()] += timestamp - prev_start_time;
                }
                call_stack.push(func_id);
                prev_start_time = timestamp;
            }else {
                execution_times[call_stack.top()] += timestamp - prev_start_time + 1;
                prev_start_time = timestamp + 1;
                call_stack.pop();
            }
        }
        return execution_times;
    }
};