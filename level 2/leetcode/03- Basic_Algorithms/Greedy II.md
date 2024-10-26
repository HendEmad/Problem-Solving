<details>
  <summary><strong><a href=https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/>partitioning into minimum number of deci binary numbers</a></strong></summary>

```cpp
class Solution {
public:
    int minPartitions(string n) {
        int max_digit = 0;
        for(char c : n) {
            max_digit = max(max_digit, c - '0');
        }
        return max_digit;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/>minimum number of operations to move all balls to each box</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);

        int count = 0, ops = 0;
        for (int i = 0; i < n; ++i) {
            answer[i] += ops;
            if (boxes[i] == '1') 
                ++count;

            ops += count;
        }

        count = 0, ops = 0;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] += ops;
            if (boxes[i] == '1') 
                ++count;
            ops += count;
        }

        return answer;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/>group the people given the group size they belong to</a></strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> groups;
        vector<vector<int>> result;

        for (int i = 0; i < groupSizes.size(); ++i) {
            groups[groupSizes[i]].push_back(i);
            if (groups[groupSizes[i]].size() == groupSizes[i]) {
                result.push_back(groups[groupSizes[i]]);
                groups[groupSizes[i]].clear();
            }
        }

        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/>restore the array from adjacent pairs</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for (auto& pair : adjacentPairs) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }

        int start;
        for (auto& [num, neighbors] : adj) {
            if (neighbors.size() == 1) {
                start = num;
                break;
            }
        }

        vector<int> result;
        unordered_set<int> visited;
        result.push_back(start);
        visited.insert(start);

    
        while (result.size() < adj.size()) {
            int current = result.back();
            for (int neighbor : adj[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    result.push_back(neighbor);
                    visited.insert(neighbor);
                    break;
                }
            }
        }

        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/>find valid matrix given row and column sums</a></strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= matrix[i][j];
                colSum[j] -= matrix[i][j];
            }
        }
        
        return matrix;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/>minimum add to make parentheses valid</a></strong></summary>

```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        for (char c : s) 
            if (c == '(') 
                open++;
            else 
                if (open > 0) 
                    open--;
                else 
                    close++;
                    
        return open + close;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/score-after-flipping-matrix/>score after flipping matrix</a></strong></summary>

```cpp
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int score = 0;

        for (int i = 0; i < m; ++i) 
            if (grid[i][0] == 0) 
                for (int j = 0; j < n; ++j) 
                    grid[i][j] ^= 1;

        for (int j = 0; j < n; ++j) {
            int ones = 0;
            for (int i = 0; i < m; ++i) 
                if (grid[i][j] == 1) 
                    ones++;
            
            ones = max(ones, m - ones);
            score += ones * (1 << (n - j - 1));
        }

        return score;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/>minimum number of operations to reinitialize a permutation</a></strong></summary>

```cpp
class Solution {
public:
    int reinitializePermutation(int n) {
        int steps = 0;
        int i = 1;        
        while (true) {
            i = (i % 2 == 0) ? i / 2 : n / 2 + (i - 1) / 2;
            steps+9+;
            
            if (i == 1) 
                break;
        }
        
        return steps;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/queue-reconstruction-by-height/>queue reconstruction by height</a></strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        vector<vector<int>> queue;
        for (auto& p : people) {
            queue.insert(queue.begin() + p[1], p);
        }

        return queue;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/reduce-array-size-to-the-half/>reduce array size to the half</a></strong></summary>

```cpp
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) 
            freq[num]++;

        vector<int> counts;
        for (auto& [num, count] : freq) 
            counts.push_back(count);

        sort(counts.rbegin(), counts.rend());

        int removed = 0, sets = 0, half = arr.size() / 2;
        for (int count : counts) {
            removed += count;
            sets++;
            if (removed >= half) 
                break;
        }

        return sets;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/check-if-a-string-can-break-another-string/>check if a string can break another string</a></strong></summary>

```cpp
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        bool s1BreaksS2 = true, s2BreaksS1 = true;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] < s2[i]) 
                s1BreaksS2 = false;
            
            if (s2[i] < s1[i]) 
                s2BreaksS1 = false;
        }

        return s1BreaksS2 || s2BreaksS1;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/>smallest string with a given numeric value</a></strong></summary>

```cpp
class Solution {
public:
    string getSmallestString(int n, int k) {
        string result(n, 'a');
        k -= n;

        for (int i = n - 1; i >= 0 && k > 0; --i) {
            int add = min(25, k);
            result[i] += add;
            k -= add;
        }

        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/>minimum numbers of function calls to make target array</a></strong></summary>

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0, maxDoubles = 0;
        
        for (int num : nums) {
            int doubles = 0;
            while (num > 0) {
                if (num % 2 == 1) {
                    operations++;
                    num--;
                }
                if (num > 0) {
                    num /= 2;
                    doubles++;
                }
            }
            maxDoubles = max(maxDoubles, doubles);
        }

        return operations + maxDoubles;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/>minimum elements to add to form a given sum</a></strong></summary>

```cpp
class Solution {
public:
    int minElements(vector<int>& nums, int limit, long long goal) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long diff = abs(goal - sum);
        
        return (diff + limit - 1) / limit;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/remove-duplicate-letters/>remove duplicate letters</a></strong></summary>

```cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> inResult(26, false);
        string result = "";

        for (char c : s) 
            freq[c - 'a']++;

        for (char c : s) {
            freq[c - 'a']--;
            if (inResult[c - 'a']) 
                continue;

            while (!result.empty() && result.back() > c && freq[result.back() - 'a'] > 0) {
                inResult[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(c);
            inResult[c - 'a'] = true;
        }

        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/dota2-senate/>dota2 senate</a></strong></summary>

```cpp
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        int n = senate.size();
        
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }
        
        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front();
            int d = dire.front();
            radiant.pop();
            dire.pop();
            
            if (r < d)
                radiant.push(r + n);
            else
                dire.push(d + n);
        }
        
        return radiant.empty() ? "Dire" : "Radiant";
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/string-without-aaa-or-bbb/>string without aaa or bbb</a></strong></summary>

```cpp
class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string result;
        
        while (a > 0 || b > 0) {
            bool writeA = false;
            int len = result.length();
            
            if (len >= 2 && result[len - 1] == result[len - 2]) {
                if (result[len - 1] == 'b')
                    writeA = true;
            } else {
                if (a >= b)
                    writeA = true;
            }
            
            if (writeA) {
                result += 'a';
                --a;
            } else {
                result += 'b';
                --b;
            }
        }
        
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/>form array by concatenating subarrays of another array</a></strong></summary>

```cpp
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int idx = 0;
        for (const auto& group : groups) {
            bool found = false;
            while (idx + group.size() <= nums.size()) {
                if (equal(group.begin(), group.end(), nums.begin() + idx)) {
                    found = true;
                    idx += group.size();
                    break;
                }
                ++idx;
            }
            if (!found) 
                return false;
        }
        return true;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/>maximum absolute sum of any subarray</a></strong></summary>

```cpp
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0, currMax = 0, currMin = 0;
        
        for (int num : nums) {
            currMax = max(num, currMax + num);
            maxSum = max(maxSum, currMax);
            
            currMin = min(num, currMin + num);
            minSum = min(minSum, currMin);
        }
        
        return max(maxSum, abs(minSum));
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/divide-two-integers/>divide two integers</a></strong></summary>

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) 
            return INT_MAX;
        
        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);
        long long result = 0;
        
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            result += multiple;
        }
        
        return (dividend > 0) == (divisor > 0) ? result : -result;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/koko-eating-bananas/>koko eating bananas</a></strong></summary>

```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int k = left + (right - left) / 2;
            int hours = 0;
            
            for (int pile : piles) 
                hours += (pile + k - 1) / k;
            
            
            if (hours <= h) 
                right = k;
            else 
                left = k + 1;
        }
        
        return left;
    }
};
```
</details>