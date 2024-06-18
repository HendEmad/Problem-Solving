class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int baseSatisfaction = 0;
        int maxExtraSatisfaction = 0;
        int currentExtraSatisfaction = 0;

        // Calculate base satisfaction (customers satisfied when owner is not grumpy)
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                baseSatisfaction += customers[i];
            }
        }

        // Sliding window to find the maximum extra satisfaction
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 1) {
                currentExtraSatisfaction += customers[i];
            }
            if (i >= minutes && grumpy[i - minutes] == 1) {
                currentExtraSatisfaction -= customers[i - minutes];
            }
            maxExtraSatisfaction = max(maxExtraSatisfaction, currentExtraSatisfaction);
        }

        return baseSatisfaction + maxExtraSatisfaction;
    }
};