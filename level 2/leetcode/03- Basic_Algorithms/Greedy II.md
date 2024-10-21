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
            steps++;
            
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

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/count-pairs-of-equal-substrings-with-minimum-difference/>count pairs of equal substrings with minimum difference</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/reduce-array-size-to-the-half/>reduce array size to the half</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/check-if-a-string-can-break-another-string/>check if a string can break another string</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/minimum-cost-to-connect-sticks/>minimum cost to connect sticks</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/put-boxes-into-the-warehouse-i/>put boxes into the warehouse i</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/>smallest string with a given numeric value</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/>minimum numbers of function calls to make target array</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/>minimum elements to add to form a given sum</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/remove-duplicate-letters/>remove duplicate letters</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/dota2-senate/>dota2 senate</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/string-without-aaa-or-bbb/>string without aaa or bbb</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/>form array by concatenating subarrays of another array</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/4-keys-keyboard/>4 keys keyboard</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/>maximum absolute sum of any subarray</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/divide-two-integers/>divide two integers</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/koko-eating-bananas/>koko eating bananas</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/shortest-distance-to-target-color/>shortest distance to target color</a></strong></summary>

```cpp

```
</details>