<details>
  <summary><strong><a href="https://leetcode.com/problems/diagonal-traverse-ii/"> 1424.diagonal traverse ii </a></strong></summary>

```cpp
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector <int> result;
        queue <pair <int, int>> q;
        q.push({0, 0});

        while (!q.empty()){
            auto p = q.front();
            q.pop();
            result.push_back(nums[p.first][p.second]);

            if (p.second == 0 && p.first + 1 < nums.size())
                q.push({p.first + 1, 0});
            
            if (p.second + 1 < nums[p.first].size())
                q.push({p.first, p.second + 1});
            
        }
        return result;    
    }
};
```

</details>

<details>
  <summary><strong><a href = "https://leetcode.com/problems/partition-array-into-disjoint-intervals/">915.partition array into disjoint intervals</a></strong></summary>

```cpp
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
        
        for(int i = 0; i < nums.size(); i++)
            if(maxLeft[i] <= minRight[i+1])
                return i+1;

        delete[] maxLeft;
        delete[] minRight;

        return -1;
    }
};
```

</details>

<details>
  <summary><strong><a href = "https://leetcode.com/problems/maximum-width-ramp/">962.maximum width ramp</a></strong></summary>

```cpp
// Solution 1; time limit exceed
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(nums[i] <= nums[j])
                    ans = max(ans, j-i);
        
        return ans;
    }
};

// Solution 2: 
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack <int> stk; 
        int n = nums.size();

        for(int i = 0; i < n; i++)
            if(stk.empty() || nums[stk.top()] > nums[i])
                stk.push(i);
        

        int best = 0;
        for(int j = n-1; j >= 0; j--){
            while(!stk.empty() && nums[stk.top()] <= nums[j]){
                int i = stk.top();
                stk.pop();
                best = max(best, j-i);
            }
        }
        return best;
    }
};
```

</details>

<details>
  <summary><strong><a href = "https://leetcode.com/problems/maximize-distance-to-closest-person/">849.maximize distance to closest person</a></strong></summary>

```cpp
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int maxDistance = 0;
        int left = -1;
        int right = 0;

        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) 
                left = i;
            else {
                while ((right < n && seats[right] == 0) || right < i) 
                    ++right;
                

                int leftDistance = left == -1 ? n : i - left;
                int rightDistance = right == n ? n : right - i;
                int distance = std::min(leftDistance, rightDistance);
                maxDistance = std::max(maxDistance, distance);
            }
        }

        return maxDistance;
    }
};
```

</details>

<details>
  <summary><strong><a href = "https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/">1144.decrease elements to make array zigzag</a></strong></summary>

```cpp
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
        return min(oddCount, evenCount);
    }
};
```
</details>

<details>
  <summary><strong><a href = "https://leetcode.com/problems/global-and-local-inversions/">775.global and local inversions</a></strong></summary>

```cpp
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
```
</details>

<details>
  <summary><strong><a href = "https://leetcode.com/problems/product-of-the-last-k-numbers/">1352.product of the last k numbers</a></strong></summary>

```cpp
class ProductOfNumbers {
private:
    vector <int> products;
    int product;
public:
    ProductOfNumbers() {
        products.clear();
        product = 1;
    }
    
    void add(int num) {
        if(num){
            product *= num;
            products.push_back(product);
        }
        else{
            products.clear();
            product = 1;
        }
    }
    
    int getProduct(int k) {
        if(products.size() < k)
            return 0;
        else if(k == products.size())
            return product;
        else
            return static_cast<int>(products.back() / products[products.size() - 1 - k]);
    }
};
```

</details>

<details>
  <summary><strong><a href = "https://leetcode.com/problems/maximum-swap/">670.maximum swap</a></strong></summary>

```cpp
/* 
Approach: Swap from the right to the left to scan the digits from right to left, while keeping track of the current maximum.
Whenever we find a new digit that smaller than the maximum, we update the the maximum by swapping it with the found smaller one. 
The target is to put the greater digit towards the left of the digit.
*/

/*
 3  0
 l  r
 v  v
72636
    ^
    max

to swap left and right in a constant time: (convert 72636 to 76632)
72636 - 2000 + 6000 - 6 + 2
num   - (l-r)*10^3  +(l - r)*10^0
num - (l - r)*(10^3 - 10^0)
*/

class Solution {
public:
    int maximumSwap(int num) {
        int max_digit = -1, max_loc = -1, l_digit = -1, l_loc, r_digit, r_loc;
        // move one location every time from right to left
        for(int loc = 0, n = num; n; n /= 10, loc++){
            int curr_digit = n % 10;
            if (curr_digit > max_digit){
                max_digit = curr_digit;
                max_loc = loc;
            } 
            else if (curr_digit < max_digit){
                l_digit = curr_digit;
                l_loc = loc;
                r_digit = max_digit;
                r_loc = max_loc;
            }
        }

        if (l_digit == -1)
            return num;
        else 
            return num - (l_digit - r_digit) * (int)(pow(10, l_loc) - pow(10, r_loc));
    }
};
```
</details>

<details>
  <summary><strong><a href = "https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/">1497.check if array pairs are divisible by k</a></strong></summary>

```cpp
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
```
</details>

<details>
  <summary><strong><a href = "https://leetcode.com/problems/majority-element-ii/">229.majority element ii</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector <int> result;
        unordered_map <int, int> countMap;
        int threshold = nums.size() / 3;

        for(int num: nums){
            countMap[num]++;
            if(countMap[num] > threshold && find(result.begin(), result.end(), num) == result.end())
                result.push_back(num);
        }
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href = "https://leetcode.com/problems/valid-triangle-number/">611.valid triangle number</a></strong></summary>

```cpp
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
```
</details>