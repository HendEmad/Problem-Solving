class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int maxx = -1;
        for(int i = 0; i < nums.size()-2; i++){
            maxx = max(nums[i], maxx);
            if (maxx > nums[i+2])
                return false;
        }
        return true;
    }
};
