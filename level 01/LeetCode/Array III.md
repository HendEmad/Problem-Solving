<details>
  <summary><strong><a href="https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/">find nearest point that has the same x or y coordinate</a></strong></summary>

```cpp
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int min_dist = INT_MAX;
        int res_index = -1;

        for(int i = 0; i < points.size(); i++) {
            if(points[i][0] == x || points[i][1] == y) {
                int manhattan_dist = abs(points[i][0] - x) + abs(points[i][1] - y);
                if(manhattan_dist < min_dist) {
                    min_dist = manhattan_dist;
                    res_index = i;
                }
            }
        }
        return res_index;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/find-the-distance-value-between-two-arrays/">find the distance value between two arrays</a></strong></summary>

```cpp
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;

        for(int i = 0; i < arr1.size(); i++) {
            bool is_valid = true;
            for (int j = 0; j < arr2.size(); j++) {
                if(abs(arr1[i] - arr2[j]) <= d) {
                    is_valid = false;
                    break;
                }
            }
            if(is_valid) {
                cnt++;
            }
        }
        return cnt;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/toeplitz-matrix/">toeplitz matrix</a></strong></summary>

```cpp
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size() - 1; i++) {
            for(int j = 0; j < matrix[0].size() - 1; j++) {
                if(matrix[i][j] != matrix[i+1][j+1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/">minimum value to get positive step by step sum</a></strong></summary>

```cpp
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int curr_sum = 0, min_sum = 0;

        for(int num : nums) {
            curr_sum += num;
            min_sum = min(min_sum, curr_sum);
        }
        return 1 - min_sum;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/count-largest-group/">count largest group</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/">longer contiguous segments of ones than zeros</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/shift-2d-grid/">shift 2d grid</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/">check if all 1s are at least length k places away</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/three-consecutive-odds/">three consecutive odds</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/special-positions-in-a-binary-matrix/">special positions in a binary matrix</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/minimum-distance-to-the-target-element/">minimum distance to the target element</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/find-lucky-integer-in-an-array/">find lucky integer in an array</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/shortest-word-distance/">shortest word distance</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/transpose-matrix/">transpose matrix</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/sort-array-by-parity/">sort array by parity</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/">final prices with a special discount in a shop</a></strong></summary>

```cpp

```
</details>