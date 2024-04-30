class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int oddCount = 0, evenCount = 0;
        
        if(nums.size() <= 1) 
            return 0;

        // Odd indices
        for(int i = 1; i < nums.size(); i+=2){
            if (i == nums.size() - 1){
                if(nums[i-1] <= nums[i])  oddCount += nums[i] - nums[i-1] + 1;
            }
            else{
                if(nums[i-1] <= nums[i] || nums[i+1] <= nums[i])  oddCount += nums[i] - (min(nums[i-1], nums[i+1]) - 1);
            }
        }

        // even indices
        for (int i = 0; i < nums.size(); i+=2){
            if (i == 0){
                if (nums[i] >= nums[i+1]) evenCount += nums[i] - (nums[i+1] - 1);
            }
            else if(i == nums.size() - 1){
                if (nums[i-1] <= nums[i])  evenCount += nums[i] - (nums[i-1] - 1);
            }
            else{
                if (nums[i-1] <= nums[i] || nums[i+1] <= nums[i])
                    evenCount += nums[i] - (min(nums[i-1], nums[i+1]) - 1);
            }
        }
        return min(oddCount, evenCount);
    }
};
