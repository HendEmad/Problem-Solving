class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> folders;
        
        for (const string& log : logs) {
            if (log == "../") {
                if (!folders.empty()) {
                    folders.pop();
                }
            } else if (log == "./") {
                // Do nothing
            } else {
                // Extract folder name
                string folderName = log.substr(0, log.length() - 1);
                folders.push(folderName);
            }
        }
        
        return folders.size();
    }
};