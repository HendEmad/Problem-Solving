<details>
  <summary><strong><a href=https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/>count negative numbers in a sorted matrix</a></strong></summary>

```cpp
// time: 10 minutes
class Solution {
public:
    int count_neg_numbers(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int cnt = 0;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] >= 0)
                left = mid + 1;
            else if(nums[mid] < 0) {
                cnt += (right - mid) + 1;
                right = mid - 1;
            }
        }
        return cnt;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++) {
            res += count_neg_numbers(grid[i]);
        }
        return res;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/>the k weakest rows in a matrix</a></strong></summary>

```cpp
//time = 15 minutes
class Solution {
public:
    int soliders_counter(vector<int>& rows) {
        int left = 0;  // civilians_cnt
        int right = rows.size() - 1;

        while(left <= right) {
            int mid = (right + left) / 2;
            if(rows[mid] == 0) {
                right = mid - 1;
            }
            else if(rows[mid] == 1) {
                left = mid + 1;
            }
        }
        return left;  // civilians_cnt
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector <pair <int, int>> solider_cnt;
        vector <int> res;

        for(int i = 0; i < mat.size(); i++) {
            int soliders = soliders_counter(mat[i]);
            solider_cnt.push_back({soliders, i});
        }

        sort(solider_cnt.begin(), solider_cnt.end());
        for(int i = 0; i < k; i++) {
            res.push_back(solider_cnt[i].second);
        }
        return res;
    }
};
```
</details>

<details>
  <summary><strong><a href=></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=></a></strong></summary>

```cpp

```
</details>