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
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        
        dfs(graph, 0, path, res);
        return res;
    }

private:
    void dfs(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& res) {
        path.push_back(node);
        if(node == size(graph) - 1) 
            res.push_back(path);
        else
            for(int& neighbor : graph[node])
                dfs(graph, neighbor, path, res);
        
        path.pop_back();
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/letter-tile-possibilities/>letter tile possibilities</a></strong></summary>

```cpp
class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<bool> visited(size(tiles), false);
        sort(tiles.begin(), tiles.end());
        int cnt = 0;

        backtracking(tiles, visited, cnt);
        return cnt;
    }

private:
    void backtracking(const string& tiles, vector<bool>& visited, int& cnt) {
        for(int i = 0; i < size(tiles); i++) {
            if(visited[i])
                continue;
            
            if(i > 0 && tiles[i] == tiles[i - 1] && !visited[i - 1])
                continue;

            visited[i] = true;
            cnt ++;
            backtracking(tiles, visited, cnt);
            visited[i] = false;
        }
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/count-sorted-vowel-strings/>count sorted vowel strings</a></strong></summary>

```cpp
// solution 1
class Solution {
public:
    int countVowelStrings(int n) {
        return comb(n + 4, 4);
    }

private:
    int comb(int x, int y) {
        long long res {1};
        for(int i = 1; i <= y; i++) {
            res = res * (x - i + 1) / i;
        }
        return res;
    }
};

// solution 2 - dynamic programming
class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);
        for (int i = 1; i < n; i++) 
            for (int j = 3; j >= 0; j--) 
                dp[j] += dp[j + 1];

        return accumulate(dp.begin(), dp.end(), 0);
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/iterator-for-combination/>iterator for combination</a></strong></summary>

```cpp
class CombinationIterator {
public:
    CombinationIterator(string chars, int comb_length) 
        : chars(chars), comb_length(comb_length) {
        string current;
        generate_combinations(current, 0);
    }

    string next() {
        return combs[index++];
    }

    bool hasNext() {
        return (index < size(combs));
    }

private:
    string chars {""};
    int comb_length {0};
    vector<string> combs;
    int index {0};

    void generate_combinations(string& curr, int start) {
        if (size(curr) == comb_length) {
            combs.push_back(curr);
            return;
        }
        for (int i = start; i < size(chars); i++) {
            curr.push_back(chars[i]);
            generate_combinations(curr, i + 1);
            curr.pop_back();
        }
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/>the k th lexicographical string of all happy strings of length n</a></strong></summary>

```cpp
// Solution 1: 19 ms
class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> res;
        string curr {""};
        
        generate_happy_strings(n, curr, res);
        if(k > size(res))
            return "";
        return res[k - 1];
    }

private:
    void generate_happy_strings(int n, string& curr, vector<string>& res) {
        if(size(curr) == n) {
            res.push_back(curr);
            return;
        }

        for(char c : {'a', 'b', 'c'}) {
            if(empty(curr) || curr.back() != c) {
                curr.push_back(c);
                generate_happy_strings(n, curr, res);
                curr.pop_back();
            }
        }
    }
};

// solution 2: 2 ms
class Solution {
public:
    string getHappyString(int n, int k) {
        string res {""};
        string curr {""};
        int cnt {0};

        if(generate_happy_strings(n, curr, cnt, k, res))
            return res;
        
        return "";
    }

private:
    bool generate_happy_strings(int n, string& curr, int& cnt, int k, string& res) {
        if(size(curr) == n) {
            cnt++;
            if(cnt == k) {
                res = curr;
                return true;
            }
            return false;
        }

        for(char c : {'a', 'b', 'c'}) {
            if(empty(curr) || curr.back() != c) {
                curr.push_back(c);
                if(generate_happy_strings(n, curr, cnt, k, res)) 
                    return true;

                curr.pop_back();
            }
        }
        return false;
    }
};

// Solution 3: 0 ms
class Solution {
public:
    string getHappyString(int n, int k) {
        string res {""};

        generate_happy_strings(n, "", k, res);
        return res;
    }

private:
    bool generate_happy_strings(int n, const string& curr, int k, string& res) {
        if(size(curr) == n) {
           k--;
           if(k == 0) {
            res = curr;
            return true;
           }
           return false;
        }

        for(char c : {'a', 'b', 'c'}) {
            if(empty(curr) || curr.back() != c) {
                int remain = pow(2, n - size(curr) - 1);
                if(k > remain)
                    k -= remain;
                else 
                    if(generate_happy_strings(n, curr + c, k, res))
                        return true;
            }
        }
        return false;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/path-with-maximum-gold/>path with maximum gold</a></strong></summary>

```cpp
// solution 1: 1350 ms
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int max_gold {0};
        int rows = size(grid);
        int cols = size(grid[0]);

        for(int i {0}; i < rows; i++) 
            for(int j {0}; j < cols; j++) 
                if(grid[i][j] > 0) 
                    max_gold = max(max_gold, collect_gold(grid, i, j));

        return max_gold;
    }

private:
    int collect_gold(vector<vector<int>>& grid, int x, int y) {
        if(x < 0 || x >= size(grid) || y < 0 || y >= size(grid[0]) || grid[x][y] == 0) 
            return 0;

        int gold = grid[x][y];
        grid[x][y] = 0;
        
        int max_gold {0};
        vector<pair<int, int>> directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(auto [dx, dy] : directions) 
            max_gold = max(max_gold, collect_gold(grid, x + dx, y + dy));

        grid[x][y] = gold;  // backtracking
        return gold +max_gold;
    }
};

// solution 2: 1334 ms
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int max_gold {0};
        int rows = size(grid);
        int cols = size(grid[0]);
        vector<pair<int, int>> gold_cells;

        for(int i {0}; i < rows; i++) 
            for(int j {0}; j < cols; j++) 
                if(grid[i][j] > 0) 
                    gold_cells.emplace_back(i, j);

        for(auto [x, y] : gold_cells) 
            max_gold = max(max_gold, collect_gold(grid, x, y, 0));
        
        return max_gold;
    }

private:
    int collect_gold(vector<vector<int>>& grid, int x, int y, int curr_gold) {
        if(x < 0 || x >= size(grid) || y < 0 || y >= size(grid[0]) || grid[x][y] == 0) 
            return curr_gold;

        int gold = grid[x][y];
        grid[x][y] = 0;
        
        int max_gold {0};
        vector<pair<int, int>> directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(auto [dx, dy] : directions) 
            max_gold = max(max_gold, collect_gold(grid, x + dx, y + dy, curr_gold + gold));

        grid[x][y] = gold;  // backtracking
        return max_gold;
    }
};

// solution 3: 1325 ms
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int max_gold {0};
        int rows = size(grid);
        int cols = size(grid[0]);

        for (int i {0}; i < rows; ++i) 
            for (int j {0}; j < cols; ++j) 
                if (grid[i][j] > 0) 
                    max_gold = max(max_gold, dfs(grid, i, j));

        return max_gold;
    }

private:
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) 
            return 0;

        int gold = grid[x][y];
        grid[x][y] = 0;

        int max_gold {0};
        vector<pair<int, int>> directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto [dx, dy] : directions) {
            max_gold = max(max_gold, dfs(grid, x + dx, y + dy));
        }

        grid[x][y] = gold; // Backtracking
        
        return gold + max_gold;
    }
};

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/>check if number is a sum of powers of three</a></strong></summary>

```cpp
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n > 0) {
            if(n % 3 == 2)
                return false;
            n /= 3; 
        }
        return true;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/beautiful-arrangement/>beautiful arrangement</a></strong></summary>

```cpp
// solution 1: 47 ms
class Solution {
public:
    int countArrangement(int n) {
        vector<int> visited (n + 1, 0);
        return backtracking(n, 1, visited);
    }

private:
    int backtracking(int& n, int pos, vector<int>& visited) {
        if(pos > n)
            return 1;

        int cnt {0};
        for(int i {1}; i <= n; i++) 
            if(!visited[i] && (i % pos == 0 || pos % i == 0)) {
                visited[i] = 1;
                cnt += backtracking(n, pos + 1, visited);
                visited[i] = 0;
            }

        return cnt;
    }
};

// solution 2: 3 ms
class Solution {
public:
    int countArrangement(int n) {
        vector<int> memo (1 << n, -1);
        return backtracking(n, 1, 0, memo);
    }

private:
    int backtracking(int n, int pos, int mask, vector<int>& memo) {
        if(pos > n)
            return 1;

        if(memo[mask] != -1)
            return memo[mask];

        int cnt {0};
        for(int i {1}; i <= n; i++) 
            if((mask & (1 << (i - 1))) == 0 && (i % pos == 0 || pos % i == 0)) 
                cnt += backtracking(n, pos + 1, mask | (1 << (i - 1)), memo);

        return memo[mask] = cnt;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/numbers-with-same-consecutive-differences/>numbers with same consecutive differences</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        
        for (int i {1}; i <= 9; i++) {
            backtracking(n - 1, k, i, res);
        }
        
        return res;
    }

private:
    void backtracking(int n, int k, int curr, vector<int>& res) {
        if (n == 0) {
            res.push_back(curr);
            return;
        }
        
        int last_digit = curr % 10;
        if (last_digit + k <= 9) 
            backtracking(n - 1, k, curr * 10 + (last_digit + k), res);
        
        if (k > 0 && last_digit - k >= 0) {  // avoid duplicates like when k =0
            backtracking(n - 1, k, curr * 10 + (last_digit - k), res);
        }
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/split-array-into-fibonacci-sequence/>split array into fibonacci sequence</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> res;
        
        if (dfs(num, res, 0)) 
            return res;
        
        return {};
    }
    
private:
    bool dfs(const string& num, vector<int>& res, int index) {
        if (index == size(num) && size(res) >= 3) 
            return true;
        
        long long curr_num = 0;
        for (int i = index; i < size(num); ++i) {

            // No leading zeroes unless it's '0'
            if (i > index && num[index] == '0') 
                break; 

            curr_num = curr_num * 10 + (num[i] - '0');
            // if curr_num exceed 32-bit integer limit
            if (curr_num > INT_MAX) 
                break; 

            if (size(res) < 2 || curr_num == (long long)res[size(res) - 1] + res[size(res) - 2]) {
                res.push_back(curr_num);

                if (dfs(num, res, i + 1)) 
                    return true;
                
                res.pop_back();
            } 
            // condition: no point in continuing if the current number exceeds the sum
            else if (size(res) >= 2 && curr_num > (long long) res[size(res) - 1] + res[size(res) - 2]) {
                break; 
            }
        }
        return false;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/additive-number/>additive number</a></strong></summary>

```cpp
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = size(num);
        for (int i {1}; i <= n / 2; ++i) {
            if (num[0] == '0' && i > 1) 
                break; 
            
            long long num1 = stoll(num.substr(0, i));
            for (int j = 1; max(i, j) <= n - i - j; ++j) {
                if (num[i] == '0' && j > 1) 
                    break; 
                
                long long num2 = stoll(num.substr(i, j));
                if (is_valid(num, i + j, num1, num2)) 
                    return true;
            }
        }
        return false;
    }
    
private:
    bool is_valid(const string& num, int start, long long num1, long long num2) {
        while (start < size(num)) {
            long long sum = num1 + num2;
            string sumStr = to_string(sum);

            if (num.substr(start, size(sumStr)) != sumStr) 
                return false;
            
            start += size(sumStr);
            num1 = num2;
            num2 = sum;
        }
        return true;
    }
};
```
</details>