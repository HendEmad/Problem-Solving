class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int* maxLeft = new int[nums.size()];
        int* minRight = new int[nums.size()];

        maxLeft[0] = nums[0];
        minRight[nums.size()-1] = nums[nums.size() - 1];

        for(int i = 1; i < nums.size(); i++){
            maxLeft[i] = max(nums[i], maxLeft[i-1]);
            minRight[nums.size()-i-1] = min(nums[nums.size()-i-1], minRight[nums.size()-i]);
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(maxLeft[i] <= minRight[i+1])
                return i+1;
        }

        delete[] maxLeft;
        delete[] minRight;

        return -1;
    }
};
