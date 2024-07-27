<details>
  <summary><strong><a href="https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/description/">1031. Maximum Sum of Two Non-Overlapping Subarrays</a></strong></summary>

```cpp
class Solution {
public:
    int n;
    int findMaxSum(vector<int>& arr, int len, int s, int e) {
        int sum = 0, ans = 0;
        for(int i = s; i < s + len; i++)
            sum += arr[i];
        
        int i = s, j = i + len;
        while(j <= e) {
            ans = max(ans, sum);
            sum += arr[j];
            sum -= arr[i];
            i++;
            j++;
        }

        ans = max(ans, sum);
        return ans;
    }

    int findSecondSubarraySum(vector<int>& arr, int start, int end, int len) {
        int left = INT_MIN, right = INT_MIN;
        if(start >= len)
            left = findMaxSum(arr, len , 0, start - 1);
        
        if(n - end - 1 >= len)
            right = findMaxSum(arr, len, end + 1, n - 1);

        return max(left, right);
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        n = nums.size();
        int sum1 = 0, sum2 = 0, ans = INT_MIN;

        for(int i = 0; i < firstLen; i++)
            sum1 += nums[i];
        
        int j = firstLen - 1, i = 0;
        while(j < n) {
            sum2 = findSecondSubarraySum(nums, i, j, secondLen);
            ans = max(ans, (sum1 + sum2));
            j++;
            if(j < n)
                sum1 += nums[j];
            sum1 -= nums[i];
            i++;    
        }
        ans = max(ans, (sum1 + sum2));
        return ans;
    }
};
```
</details>

<details>
  <summary><strong><a href=""></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=""></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=""></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=""></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=""></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=""></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=""></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=""></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=""></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=""></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=""></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=""></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=""></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=""></a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=""></a></strong></summary>

```cpp

```
</details>