// Solution 1; time limit exceed
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] <= nums[j])
                    ans = max(ans, j-i);
            }
        }
        return ans;
    }
};

// Solution 2: 
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack <int> stk;  // maintains indices of values in decreasing order from left to right
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(stk.empty() || nums[stk.top()] > nums[i])
                stk.push(i);
        }

        int best = 0;
        for(int j = n-1; j >= 0; j--){
            while(!stk.empty() && nums[stk.top()] <= nums[j]){
                int i = stk.top();
                stk.pop();
                best = max(best, j-i);
            }
        }
        return best;
    }
};
