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
  <summary><strong><a href=https://leetcode.com/problems/guess-number-higher-or-lower/description/>guess number higher or lower</a></strong></summary>

```cpp
// time: 7 minutes
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long low = 1;
        long high = n;
        
        while(low <= high) {
            long mid = (low + high) / 2;
            long value = guess(mid);
            if(value == 0)
                return mid;
            else if(value == -1)
                high = mid - 1;
            else if(value == 1)
                low = mid + 1;
        }
        return -1;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/arranging-coins/description/>arranging coins</a></strong></summary>

```cpp
// time = 20 minutes
// linear/ greedy [o(n)]
class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1, res = 0;

        while(i <= n) {
            n -= i;
            res ++;
            i ++;
        }
        return res;
    }
};

// Binary search [O(log n)]
class Solution {
public:
    int arrangeCoins(int n) {
        long low = 0; 
        long high = n;
        
        while(low <= high) {
            long mid = (low + high) / 2;
            long coins_num = (mid * (mid + 1)) / 2;   // 1 + 2 + 3 + 4 + ........ + k = k * (k + 1) / 2
            
            if(n < coins_num)
                high = mid - 1;
            else if (n > coins_num)
                low = mid + 1;
            else
                return mid;
        }
        return high;
    }
};

// Constant time/ Mathematical approach O(1)
/*
sum(k) refers to the number of coins needed to build k complete rows
sum(k) = (k * (k + 1)) / 2
To find the largest k, the sum of numbers must be <= the whole number of coins
(k^2 + k) <= 2n  ==>  k^2 + k - 2n <= 0, by solving this equation:
k = (-1 +- sqrt(1 + 8n)) / 2 
*/
class Solution {
public:
    int arrangeCoins(int n) {
        return floor (-1 + sqrt(1 + 8.0 * n)) / 2;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/valid-perfect-square/>valid perfect square</a></strong></summary>

```cpp
// time = 10 minutes
// linear time/ greedy approach O(n)
class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long i = 1; i <= num; i++) {
            if(i * i == num)
                return true;
        }
        return false;
    }
};

// Binary search approach O(log n)
class Solution {
public:
    bool isPerfectSquare(long num) {
        int low = 1;
        long high = num;

        while(low <= high) {
            long mid = (low + high) / 2;
            
            if(mid * mid == num)
                return true;
            else if (num > mid * mid)
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return false;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/first-bad-version/>first bad version</a></strong></summary>

```cpp
// time = 6 minutes
// linear time/ greedy approach O(n)
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int bad_version = 0;
        for(int i = 1; i <= n; i++) {
            if(isBadVersion(i)){
                bad_version = i;
                break;
            }
        }
        return bad_version;
    }
};

// Binary search O(log n)
class Solution {
public:
    int firstBadVersion(long n) {
        int low = 1;
        long high = n;
        int res;
        
        while(low < high) {
            int mid = (low + high) / 2;
            if(isBadVersion(mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/>egg drop with 2 eggs and n floors</a></strong></summary>

```cpp
// time: 15 minutes
//linear time O(n)
class Solution {
public:
    int twoEggDrop(int n) {
        int res = 0;
        while(n > 0) {
            res ++;
            n -= res;
        }
        return res;
    }
};

// O(log n) solution
class Solution {
public:
    int twoEggDrop(int n) {
        int low = 1;
        int high = n;

        while(low < high) {
            int mid = (low + high) / 2;
            // floors number covered must be <= n
            // no.of drops = 1 + 2 + 3 + 4 + ....... + k
            int floors_num = (mid * (mid + 1)) / 2;
            if(floors_num >= n)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/>maximum nesting depth of two valid parentheses strings</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth = 0;
        int n = seq.size();
        vector <int> res (n, 0);
        for(int i = 0; i < n; i++) {
            if(seq[i] == '(') {
                depth++;
                res[i] = depth % 2;
            } 
            else {
                res[i] = depth % 2;
                depth--;
            }
        }
        return res;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/description/>Find Positive Integer Solution for a Given Equation</a></strong></summary>

```cpp
// Two pointers approach O(n)
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector <int>> res;
        int x = 1, y = 1000;

        while(x <= 1000 && y >= 1) {
            int value = customfunction.f(x, y);
            if(value == z) {
                res.push_back({x, y});
                x++;
                y--;
            }
            else {
                if(value < z) 
                    x++;
                else
                    y--;
            }
        }
        return res;
    }
};

// Bianry search O(n*log n)
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector <int>> res;
        int x = 1;
        
        while(x <= 1000 ) {
            int low = 1, high = 1000;
            // apply BS for y
            while(low <= high) {
                int mid = (low + high) / 2;
                int value = customfunction.f(x, mid);

                if(value == z) {
                    res.push_back({x, mid});
                    break;
                }
                else if(value < z)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            x++;
        }
        return res;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/description/>compare strings by frequency of the smallest character</a></strong></summary>

```cpp
// Brute force approach, O(n^2)
class Solution {
public:
    int calc_freq(const string &s) {
        char smallest = 'z' + 1;
        int cnt = 0;
        for(char c : s) {
            if(c < smallest) {
                smallest = c;
                cnt = 1;
            }
            else if(c == smallest)
                cnt++;
        }
        return cnt;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = words.size();
        vector <int> words_freq(n);
        for(int i = 0; i < n; i++) {
            words_freq[i] = calc_freq(words[i]);
        }

        vector <int> res;
        for(const string& query : queries) {
            int query_freq = calc_freq(query);
            int cnt = 0;

            for(int freq : words_freq) {
                if(query_freq < freq) 
                    cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }
};

// Binary Search approach, O(n*log n)
class Solution {
public:
    int calc_freq(const string &s) {
        char smallest = 'z' + 1;
        int cnt = 0;
        for(char c : s) {
            if(c < smallest) {
                smallest = c;
                cnt = 1;
            }
            else if(c == smallest)
                cnt++;
        }
        return cnt;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = words.size();
        vector <int> word_freqs(n);
        for(int i = 0; i < n; i++) {
            word_freqs[i] = calc_freq(words[i]);
        }

        sort(word_freqs.begin(), word_freqs.end());
        
        vector <int> res;
        for(const string& query : queries) {
            int query_freq = calc_freq(query);
            auto it = upper_bound(word_freqs.begin(), word_freqs.end(), query_freq);
            int cnt = word_freqs.end() - it;

            res.push_back(cnt);
        }
        return res;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/>Capacity To Ship Packages Within D Days</a></strong></summary>

```cpp
// Binary search approach O(n*log n)
class Solution {
public:
    bool can_ship(const vector<int>& weights, int capacity, int days) {
        int curr_weight = 0;  // weight of the day
        int required_days = 1;  // at least one day

        for(int weight : weights) {
            if(curr_weight + weight > capacity) {
                required_days ++;
                curr_weight = weight;              
                if(required_days > days)
                    return false;                                                         
            } else {
                curr_weight += weight;
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // min_capacity = low
        // max_capacity = high
        int min_capacity = *max_element(weights.begin(), weights.end());  // max weight of each package 
        int max_capacity = accumulate(weights.begin(), weights.end(), 0);  // sum of all weights

        while(min_capacity < max_capacity) {
            int mid = (min_capacity + max_capacity) / 2;
            if(can_ship(weights, mid, days))    
                max_capacity = mid;
            else
                min_capacity = mid + 1;  // increase capacity
        }
        return min_capacity;
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
