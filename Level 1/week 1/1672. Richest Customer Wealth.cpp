class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for (const auto& customer : accounts) {
            int wealth = 0;
            for (int money : customer) {
                wealth += money;
            }
            maxWealth = std::max(maxWealth, wealth);
        }
        return maxWealth;
    }
};