class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        for (const auto& query : queries) {
            result.push_back(isMatch(query, pattern));
        }
        return result;
    }
    
    bool isMatch(const string& query, const string& pattern) {
        int queryPtr = 0, patternPtr = 0;
        while (queryPtr < query.size() && patternPtr < pattern.size()) {
            if (query[queryPtr] == pattern[patternPtr]) {
                queryPtr++;
                patternPtr++;
            } else if (isupper(query[queryPtr])) {
                return false;
            } else {
                queryPtr++;
            }
        }
        if (patternPtr != pattern.size()) return false;
        while (queryPtr < query.size()) {
            if (isupper(query[queryPtr])) return false;
            queryPtr++;
        }
        return true;
    }
};