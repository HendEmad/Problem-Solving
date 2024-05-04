// First solution; time complexity = O(n^3); time limit exceed
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                for(int k = j+1; k < nums.size(); k++){
                    if(nums[i] + nums[j] > nums[k] && 
                    nums[i] + nums[k] > nums[j] &&
                    nums[j] + nums[k] > nums[i])
                        ans += 1;
                }
            }
        }
        return ans;
    }
};

// Optimized solution; time complexity = O(n^2)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int a = nums.size()-1; a > 0; a--){
            int b = 0;
            int c = a - 1;
            while(b < c){
                if(nums[b] + nums[c] > nums[a]){  // valid triangle
                    ans += c - b;
                    c -= 1;
                }
                else{  // not valid triangle; larger values are needed; move b to b+1
                    b += 1;
                }
            }
        }
        return ans;
    }
};
