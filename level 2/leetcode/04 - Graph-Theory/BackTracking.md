<details>
  <summary><strong><a href=https://leetcode.com/problems/count-of-matches-in-tournament/>count of matches in tournament</a></strong></summary>

```cpp
class Solution {
public:
    int numberOfMatches(int n) {
        int matches = 0;
        while(n > 1) {
            if(n % 2 == 0) {
                matches = matches + n / 2;
                n /= 2;
            }
            else {
                matches = matches + (n - 1) / 2;
                n = ((n - 1) / 2) + 1;
            }
        }
        return matches;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/sum-of-all-subset-xor-totals/>sum of all subset xor totals</a></strong></summary>

```cpp
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int total_xor_sum = 0;
        int n = nums.size();
        int subsets = 1 << n;

        for(int i = 0; i < subsets; i++) {
            int current_xor = 0;
            for(int j = 0; j < n; j++) 
                if(i & (1 << j)) 
                    current_xor ^= nums[j];
            
            total_xor_sum += current_xor;
        }
        return total_xor_sum;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/binary-watch/>binary watch</a></strong></summary>

```cpp
'''
__builtin_popcount(h) --> counts no.of LEDs that are on in the hour (h)
__builtin_popcount(m) --> counts no.of LEDs that are on in the minutes (m)
'''
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;

        for(int h = 0; h < 12; h++) {
            for(int m = 0; m < 60; m++) {
                if(__builtin_popcount(h) + __builtin_popcount(m) == turnedOn)
                    res.push_back(to_string(h) + ":" + 
                                 (m < 10 ? "0" : "") + 
                                 (to_string(m)));
            }
        }
        return res;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/all-paths-from-source-to-target/>all paths from source to target</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/letter-tile-possibilities/>letter tile possibilities</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/count-sorted-vowel-strings/>count sorted vowel strings</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/iterator-for-combination/>iterator for combination</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/>the k th lexicographical string of all happy strings of length n</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/path-with-maximum-gold/>path with maximum gold</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/brace-expansion/>brace expansion</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/>check if number is a sum of powers of three</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/beautiful-arrangement/>beautiful arrangement</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/factor-combinations/>factor combinations</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/numbers-with-same-consecutive-differences/>numbers with same consecutive differences</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/split-array-into-fibonacci-sequence/>split array into fibonacci sequence</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/additive-number/>additive number</a></strong></summary>

```cpp

```
</details>