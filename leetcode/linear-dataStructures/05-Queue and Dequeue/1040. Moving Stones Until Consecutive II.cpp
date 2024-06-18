class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
    
        // Calculate max moves
        int max_moves = max(stones[n-1] - stones[1] - (n - 2), stones[n-2] - stones[0] - (n - 2));
    
        // Calculate min moves
        int min_moves = n;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && stones[j] <= stones[i] + n - 1) {
                ++j;
            }
            int already_in_window = j - i;
            if (already_in_window == n - 1 && stones[j - 1] - stones[i] == n - 2) {
                // Special case: one stone out of place, edge case
                min_moves = min(min_moves, 2);
            } else {
                min_moves = min(min_moves, n - already_in_window);
            }
        }
    
        return {min_moves, max_moves};
    }
};