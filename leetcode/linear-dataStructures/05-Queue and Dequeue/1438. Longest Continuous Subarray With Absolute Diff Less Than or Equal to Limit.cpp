class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int left = 0, maxLength = 0;
    
        for (int right = 0; right < nums.size(); ++right) {
            // Maintain maxDeque
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);
        
            // Maintain minDeque
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);
        
            // Check if the current window is valid
            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                left++;
                if (maxDeque.front() < left) maxDeque.pop_front();
                if (minDeque.front() < left) minDeque.pop_front();
            }
        
            // Update the maximum length of valid subarray
            maxLength = max(maxLength, right - left + 1);
        }
    
        return maxLength;
    }
};