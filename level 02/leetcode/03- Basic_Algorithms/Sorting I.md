<details>
  <summary><strong><a href=https://leetcode.com/problems/shuffle-string/description/>Shuffle String</a></strong></summary>

```cpp
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string result(s.size(), ' ');
        for (int i = 0; i < s.size(); ++i) 
            result[indices[i]] = s[i];
        
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/sorting-the-sentence/description/>Sorting the Sentence</a></strong></summary>

```cpp
class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(9);  
        string word = "";
        
        for (char c : s) {
            if (isdigit(c)) {
                int index = c - '1';  
                words[index] = word;  
                word = "";
            } else if (c == ' ') 
                continue;  
            else 
                word += c;  
        }
        
        string result = "";
        for (string w : words) 
            if (!w.empty()) 
                if (!result.empty()) result += " ";
                result += w;
        
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/increasing-decreasing-string/description/>Increasing Decreasing String</a></strong></summary>

```cpp
class Solution {
public:
    string sortString(string s) {
        vector<int> count(26, 0);
        for (char c : s) 
            count[c - 'a']++;
        
        string result;
        while (result.size() < s.size()) {
            for (int i = 0; i < 26; ++i) {
                if (count[i] > 0) {
                    result += ('a' + i);
                    count[i]--;
                }
            }
            for (int i = 25; i >= 0; --i) {
                if (count[i] > 0) {
                    result += ('a' + i);
                    count[i]--;
                }
            }
        }
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/description/>Minimum Subsequence in Non-Increasing Order</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int subSum = 0;
        vector<int> result;
        
        for (int num : nums) {
            subSum += num;
            result.push_back(num);
            if (subSum > totalSum - subSum) 
                break;
        }
        
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/sort-array-by-parity-ii/description/>Sort Array By Parity II</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = 1;
        while (i < nums.size() && j < nums.size()) {
            while (i < nums.size() && nums[i] % 2 == 0) 
                i += 2;  
            while (j < nums.size() && nums[j] % 2 == 1) 
                j += 2;  
            if (i < nums.size() && j < nums.size()) 
                swap(nums[i], nums[j]);  
        }
        return nums;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/>Can Make Arithmetic Progression From Sequence</a></strong></summary>

```cpp
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); ++i) 
            if (arr[i] - arr[i - 1] != diff) 
                return false;
                
        return true;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/>Sort Integers by The Number of 1 Bits</a></strong></summary>

```cpp
class Solution {
public:
    int countBits(int n) {
        return __builtin_popcount(n);
    }

    static bool compare(int a, int b) {
        int bitsA = __builtin_popcount(a);
        int bitsB = __builtin_popcount(b);
        if (bitsA == bitsB) 
            return a < b;
        
        return bitsA < bitsB;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/maximum-units-on-a-truck/description/>Maximum Units on a Truck</a></strong></summary>

```cpp
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });
        
        int totalUnits = 0;
        
        for (const auto& box : boxTypes) {
            int count = min(box[0], truckSize);
            totalUnits += count * box[1];
            truckSize -= count;
            if (truckSize == 0) 
                break;
        }
        
        return totalUnits;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/matrix-cells-in-distance-order/description/>Matrix Cells in Distance Order/a></strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> result;
        for (int r = 0; r < rows; r++) 
            for (int c = 0; c < cols; c++) 
                result.push_back({r, c});
        
        sort(result.begin(), result.end(), 
        [rCenter, cCenter](const vector<int>& a, const vector<int>& b) {
            return abs(a[0] - rCenter) + abs(a[1] - cCenter) < abs(b[0] - rCenter) + abs(b[1] - cCenter);
        });
        
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/relative-sort-array/description/>Relative Sort Array</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> count;
        vector<int> result;

        for (int num : arr1) 
            count[num]++;

        for (int num : arr2) {
            while (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }

        vector<int> remaining;
        for (const auto& entry : count) 
            for (int i = 0; i < entry.second; i++) 
                remaining.push_back(entry.first);

        sort(remaining.begin(), remaining.end());
        result.insert(result.end(), remaining.begin(), remaining.end());

        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/>Average Salary Excluding the Minimum and Maximum Salary</a></strong></summary>

```cpp
class Solution {
public:
    double average(vector<int>& salary) {
        int minSalary = INT_MAX;
        int maxSalary = INT_MIN;
        double total = 0.0;
        
        for (int sal : salary) {
            total += sal;
            minSalary = min(minSalary, sal);
            maxSalary = max(maxSalary, sal);
        }
        
        total -= (minSalary + maxSalary);
        return total / (salary.size() - 2);
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/sort-array-by-increasing-frequency/description/>Sort Array by Increasing Frequency</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freqMap;

        for (int num : nums) 
            freqMap[num]++;

        vector<pair<int, int>> freqVec(freqMap.begin(), freqMap.end());
        sort(freqVec.begin(), freqVec.end(), 
        [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second == b.second ? a.first > b.first : a.second < b.second;
        });

        vector<int> result;
        for (const auto& entry : freqVec) 
            result.insert(result.end(), entry.second, entry.first);

        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/largest-perimeter-triangle/description/>Largest Perimeter Triangle</a></strong></summary>

```cpp
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 2; --i) 
            if (nums[i] < nums[i - 1] + nums[i - 2]) 
                return nums[i] + nums[i - 1] + nums[i - 2];
        
        return 0;
    }
};
```