class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1, end = -2;
        int minval = nums[n - 1], maxval = nums[0];

        for(int i = 1; i < n; i++){
            maxval = max(maxval, nums[i]);
            minval = min(minval, nums[n - 1 - i]);

            if(nums[i] < maxval)
                end = i;
            
            if(nums[n - 1 - i] > minval)
                start = n - 1 - i;
        }

        return end - start + 1;
    }
};
