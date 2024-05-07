class Solution {
public:
    int binarySearch(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int count = 0;

        while (left <= right) {
            int mid = (right + left) / 2;
            if (nums[mid] >= 0)
                left = mid + 1;
            else if (nums[mid] < 0) {
                count += (right - mid) + 1;
                right = mid - 1;
            }
        }
        return count;
    } 

    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++) {
            res += binarySearch(grid[i]);
        }
        return res;
    }
};