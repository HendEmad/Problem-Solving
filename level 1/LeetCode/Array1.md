<details>
  <summary><strong><a href="https://leetcode.com/problems/running-sum-of-1d-array/description/">1480. Running Sum of 1d Array</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int> result;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            result.emplace_back(sum);
        }
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/">1431. Kids With the Greatest Number of Candies</a></strong></summary>

```cpp
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool>result(n);
        for(int i = 0; i < n; i++) {
            int maxx = *max_element(candies.begin(), candies.end());
            int newCandiesNum = candies[i] + extraCandies;
            if(newCandiesNum >= maxx)
                result[i] = true;
            else
                result[i] = false;
        }
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/richest-customer-wealth/">1672. Richest Customer Wealth</a></strong></summary>

```cpp
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int result = 0;
        for(const auto &account: accounts) {
            int wealth = accumulate(account.begin(), account.end(), 0);
            result = max(wealth, result);
        }
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/shuffle-the-array/description/">1470. Shuffle the Array</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> result;
        for(int i = 0; i < n; i++) {
            result.emplace_back(nums[i]);
            result.emplace_back(nums[i + n]);
        }
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/decompress-run-length-encoded-list/description/">1313. Decompress Run-Length Encoded List</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector <int> result;
        for(int i = 0; i < size(nums); i+=2) {
            int freq = nums[i];
            int val = nums[i + 1];
            for(int i = 0; i < freq; i++) {
                result.emplace_back(val);
            }
        }
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/create-target-array-in-the-given-order/submissions/1330252016/">1389. Create Target Array in the Given Order</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector <int> result;
        for(int i = 0; i < size(nums); i++) {
            result.insert(result.begin() + index[i], nums[i]);
        }
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/count-items-matching-a-rule/description/">1773. Count Items Matching a Rule</a></strong></summary>

```cpp
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int result = 0;
        int index = (ruleKey == "type" ? 0 : ruleKey == "color" ? 1 : 2);
        for(const auto &item : items) {            
            if(ruleValue == item[index])
                result++;
        }
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/xor-operation-in-an-array/description/">1486. XOR Operation in an Array</a></strong></summary>

```cpp
class Solution {
public:
    int xorOperation(int n, int start) {
        vector <int> nums (n);
        int result = 0;
        for(int i = 0; i < n; i++) {
            result ^= (start + 2 * i);
        }
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/design-an-ordered-stream/">1656. Design an Ordered Stream</a></strong></summary>

```cpp
class OrderedStream {
private:
    vector <string> stream;
    int ptr;

public:
    OrderedStream(int n) {
        stream.resize(n+1); 
        ptr = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        stream[idKey] = value;  
        vector <string> result; 
        
        while (ptr < stream.size() && !stream[ptr].empty()) {   
            result.emplace_back(stream[ptr]);  
            ptr++; 
        }
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/sum-of-all-odd-length-subarrays/description/">1588. Sum of All Odd Length Subarrays</a></strong></summary>

```cpp
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int result = 0;
        for(int i = 0; i < size(arr); i++) {
            int startOccuranceCount = size(arr) - i;
            int endOccuranceCoount = i + 1;
            int totaloccuranceCount = startOccuranceCount * endOccuranceCoount;
            int oddOccuranceCount = totaloccuranceCount / 2 + totaloccuranceCount % 2;
            result += oddOccuranceCount * arr[i];
        }
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/count-good-triplets/description/">1534. Count Good Triplets</a></strong></summary>

```cpp
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = size(arr);
        int result = 0;

        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                for(int k = j + 1; k < n; k++) {
                    if(abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) 
                        result++;
                }
            }
        }
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/find-the-highest-altitude/description/">1732. Find the Highest Altitude</a></strong></summary>

```cpp
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0, result = 0;
        // for(int i = 0; i < size(gain); i++) {  
        //     sum += gain[i]; 
        //     result = max(result, sum);  
        // }

        // more efficient
        for(const auto &i : gain) {
            sum += i;
            result = max(result, sum);
        }
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/minimum-time-visiting-all-points/description/"><1266. Minimum Time Visiting All Points/a></strong></summary>

```cpp
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int result = 0;
        for(int i = 1; i < size(points); i++) {
            int diff_x = abs(points[i][0] - points[i-1][0]);
            int diff_y = abs(points[i][1] - points[i-1][1]);
            result += max(diff_x, diff_y);
        }
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/flipping-an-image/description/">832. Flipping an Image</a></strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for(int i = 0; i < n; i++) {
            int l = 0, r = n - 1;
            while(l <= r) {
                swap(image[i][l], image[i][r]);
                l++;
                r--;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) {
                image[i][j] = 1 - image[i][j];
            }
        }
        return image;
    }
};

// Another Solution:
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for(int i = 0; i < n; i++) {
            int l = 0, r = n - 1;
            while(l <= r) {
                image[i][r] = 1 - image[i][r];
                if(l != r) {
                    image[i][l] = 1 - image[i][l];
                    swap(image[i][l], image[i][r]);
                }
                l++;
                r--;
            }
        }
        return image;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/description/">1252. Cells with Odd Values in a Matrix</a></strong></summary>

```cpp
class Solution {
public:
    int oddCells(int rows, int cols, vector<vector<int>>& indices) {
        vector<vector<int>> result(rows, vector<int>(cols, 0));
        int cnt = 0;

        for(const auto &index: indices) {
            int row = index[0];
            int col = index[1];
            for(int i = 0; i < cols; i++) 
                result[row][i] ++;

            for(int j = 0; j < rows; j++) 
                result[j][col] ++;
        }
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) 
                if(result[i][j] % 2 != 0)
                    cnt++;
        }
        return cnt;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/">1295. Find Numbers with Even Number of Digits</a></strong></summary>

```cpp
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for(int &num : nums) {
            int digitsCnt = 0;
            while(num > 0){
                num /= 10;
                digitsCnt ++;
            }

            if(digitsCnt % 2 == 0)
                result++;
        }
        return result;
    }
};
```
</details>