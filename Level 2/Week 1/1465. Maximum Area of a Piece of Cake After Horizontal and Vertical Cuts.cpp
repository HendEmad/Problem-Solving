class Solution {
public:
    const int MOD = 1e9 + 7;

    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int maxHorizontal = max(horizontalCuts[0], h - horizontalCuts.back());
        int maxVertical = max(verticalCuts[0], w - verticalCuts.back());

        for (int i = 1; i < horizontalCuts.size(); i++) 
            maxHorizontal = max(maxHorizontal, horizontalCuts[i] - horizontalCuts[i - 1]);

        for (int i = 1; i < verticalCuts.size(); i++) 
            maxVertical = max(maxVertical, verticalCuts[i] - verticalCuts[i - 1]);

        long long maxArea = static_cast<long long>(maxHorizontal) * maxVertical;

        return maxArea % MOD;
    }
};
