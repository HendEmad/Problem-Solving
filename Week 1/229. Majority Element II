class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector <int> result;
        unordered_map <int, int> countMap;
        int threshold = nums.size() / 3;

        for(int num: nums){
            countMap[num]++;
            if(countMap[num] > threshold && find(result.begin(), result.end(), num) == result.end()){
                result.push_back(num);
            }
        }
        return result;
    }
};
