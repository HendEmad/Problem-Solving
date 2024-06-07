class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int start = 0, end = 0, totalCost = 0, maxLength = 0;
        
        while (end < n) {
            totalCost += abs(s[end] - t[end]);
            while (totalCost > maxCost) {
                totalCost -= abs(s[start] - t[start]);
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
            end++;
        }
        
        return maxLength;
    }
};