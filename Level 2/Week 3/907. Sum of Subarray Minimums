class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long result = 0;
        vector<int> prev_smaller(n, -1); // Store the index of previous smaller element
        vector<int> next_smaller(n, n);  // Store the index of next smaller element

        // Find the previous smaller element
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            prev_smaller[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Clear the stack for next pass
        while (!s.empty()) {
            s.pop();
        }

        // Find the next smaller element
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            next_smaller[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        for (int i = 0; i < n; i++) {
            long long count = (i - prev_smaller[i]) * (next_smaller[i] - i) % MOD;
            result = (result + count * arr[i]) % MOD;
        }

        return result;
    }
};