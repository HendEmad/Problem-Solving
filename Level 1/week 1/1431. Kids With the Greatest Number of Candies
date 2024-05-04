class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = *std::max_element(candies.begin(), candies.end());
        vector<bool> result;
        for (int numCandies : candies) {
            result.push_back(numCandies + extraCandies >= maxCandies);
        }
        return result;
        }
};