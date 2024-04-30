class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainders;  // to store the remainder of each element
        for(auto a: arr) 
            remainders[(a % k + k) % k] ++;
        if (remainders[0] % 2 == 1)
            return false;
        for(int i = 1; i < k; i++)
            if (remainders[i] != remainders[k - i])
                return false;
        return true;           
    }
};
