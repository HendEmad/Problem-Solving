class Solution {
public:
    int next(const vector<int>& nums, int i){
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
                continue;

            int slow = i, fast = i;

            while(nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(nums, fast)] > 0){
                slow = next(nums, slow);
                fast = next(nums, next(nums, fast));

                if(slow == fast){
                    if(slow == next(nums, slow))
                        break;
                    return true;
                }
            }

            slow = i;
            int val = nums[slow];

            while(nums[slow] * val > 0){
                int nextIndex = next(nums, slow);
                nums[slow] = 0;
                slow = nextIndex;
            }
        }
        return false;
    }
};
