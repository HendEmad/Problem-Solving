class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> candidate;
        int third = INT_MIN; 

        for (int i = n - 1; i >= 0; i--) {
            // If we find a number smaller than the potential candidate for "3", it means we've found a valid 132 pattern
            if (nums[i] < third) {
                return true;
            }
            while (!candidate.empty() && nums[i] > candidate.top()) {
                third = candidate.top();
                candidate.pop();
            }
            candidate.push(nums[i]);
        }

        return false;   
    }
};