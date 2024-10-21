<details>
  <summary><strong><a href=https://leetcode.com/problems/split-a-string-in-balanced-strings/>split a string in balanced strings</a></strong></summary>

```cpp
class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0;
        int count = 0;

        for (char c : s) {
            if (c == 'L') {
                balance++;
            } else {
                balance--;
            }

            if (balance == 0) {
                count++;
            }
        }

        return count;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/>number of rectangles that can form the largest square</a></strong></summary>

```cpp
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = 0; 
        int count = 0;  

        for (const auto& rectangle : rectangles) {
            int currentLen = min(rectangle[0], rectangle[1]); rectangle
            
            if (currentLen > maxLen) {
                maxLen = currentLen; 
                count = 1;           
            } else if (currentLen == maxLen) {
                count++;            
            }
        }

        return count; 
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/>minimum operations to make the array increasing</a></strong></summary>

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                operations += nums[i - 1] + 1 - nums[i]; 
                nums[i] = nums[i - 1] + 1; 
            }
        }
        
        return operations;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/>minimum cost to move chips to the same position</a></strong></summary>

```cpp
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int oddCount = 0;
        int evenCount = 0;

        for (int pos : position) {
            if (pos % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }

        return min(oddCount, evenCount);
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/delete-columns-to-make-sorted/>delete columns to make sorted</a></strong></summary>

```cpp
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        int n = strs.size();
        int m = strs[0].length();

        for (int j = 0; j < m; ++j) {  
            for (int i = 0; i < n - 1; ++i) {  
                if (strs[i][j] > strs[i + 1][j]) {  
                    count++;
                    break; 
                }
            }
        }

        return count;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/calculate-money-in-leetcode-bank/>calculate money in leetcode bank</a></strong></summary>

```cpp
class Solution {
public:
    int totalMoney(int n) {
        int total = 0;
        int weeks = n / 7;
        int days = n % 7;

        for (int i = 0; i < weeks; ++i) {
            total += (7 * (i + 1)) + 21;
        }

        for (int i = 0; i < days; ++i) {
            total += (weeks + 1) + i;
        }

        return total;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/last-stone-weight/>last stone weight</a></strong></summary>

```cpp
#include <vector>
#include <queue>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int> maxHeap(stones.begin(), stones.end());

        while (maxHeap.size() > 1) {
            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();

            if (stone1 != stone2) {
                maxHeap.push(stone1 - stone2);
            }
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/water-bottles/>water bottles</a></strong></summary>

```cpp
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrunk = numBottles;
        int emptyBottles = numBottles;

        while (emptyBottles >= numExchange) {
            int newBottles = emptyBottles / numExchange;
            totalDrunk += newBottles;
            emptyBottles = newBottles + (emptyBottles % numExchange);
        }

        return totalDrunk;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/>minimum changes to make alternating binary string</a></strong></summary>

```cpp
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int changesPattern1 = 0, changesPattern2 = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] != (i % 2 == 0 ? '0' : '1')) {
                changesPattern1++;
            }
            if (s[i] != (i % 2 == 0 ? '1' : '0')) {
                changesPattern2++;
            }
        }

        return min(changesPattern1, changesPattern2);
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/can-place-flowers/>can place flowers</a></strong></summary>

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        
        for (int i = 0; i < size; ++i) {
            if (flowerbed[i] == 0) {
                bool leftEmpty = (i == 0 || flowerbed[i - 1] == 0);
                bool rightEmpty = (i == size - 1 || flowerbed[i + 1] == 0);
                
                if (leftEmpty && rightEmpty) {
                    flowerbed[i] = 1; 
                    n--; 
                    if (n == 0) return true;
                }
            }
        }
        
        return n <= 0;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/>maximize sum of array after k negations</a></strong></summary>

```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() && k > 0 && nums[i] < 0; ++i) {
            nums[i] = -nums[i];
            --k;
        }
   
        int sum = 0;
        int smallest = *min_element(nums.begin(), nums.end());
        
        for (int num : nums) {
            sum += num;
        }
        
        if (k % 2 == 1) {
            sum -= 2 * smallest;  
        }
        
        return sum;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/lemonade-change/>lemonade change</a></strong></summary>

```cpp
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        
        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } else {
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
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
  <summary><strong><a href=https://leetcode.com/problems/assign-cookies/>assign cookies</a></strong></summary>

```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) i++;
            j++;
        }
        return i;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/>latest time by replacing hidden digits</a></strong></summary>

```cpp
class Solution {
public:
    string maximumTime(string time) {
        if (time[0] == '?') time[0] = (time[1] == '?' || time[1] <= '3') ? '2' : '1';
        if (time[1] == '?') time[1] = (time[0] == '2') ? '3' : '9';
        if (time[3] == '?') time[3] = '5';
        if (time[4] == '?') time[4] = '9';
        return time;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/>check if binary string has at most one segment of ones</a></strong></summary>

```cpp
class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/walking-robot-simulation/>walking robot simulation</a></strong></summary>

```cpp
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }

        int x = 0, y = 0, maxDistance = 0;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // North, East, South, West
        int dirIndex = 0;

        for (int command : commands) {
            if (command == -2) {
                dirIndex = (dirIndex + 3) % 4; // Turn left
            } else if (command == -1) {
                dirIndex = (dirIndex + 1) % 4; // Turn right
            } else {
                for (int k = 0; k < command; ++k) {
                    int newX = x + directions[dirIndex][0];
                    int newY = y + directions[dirIndex][1];
                    string pos = to_string(newX) + "," + to_string(newY);
                    if (obstacleSet.find(pos) == obstacleSet.end()) {
                        x = newX;
                        y = newY;
                        maxDistance = max(maxDistance, x * x + y * y);
                    } else {
                        break; 
                    }
                }
            }
        }

        return maxDistance;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/minimum-number-of-people-to-teach/>minimum number of people to teach</a></strong></summary>

```cpp
class Solution {
public:
    int minimumTeachings(int n, std::vector<std::vector<int>>& languages, std::vector<std::vector<int>>& friendships) {
        std::unordered_map<int, std::unordered_set<int>> userLanguages;
        std::unordered_set<int> needToLearn;
        
        for (int i = 0; i < languages.size(); ++i) {
            userLanguages[i + 1] = std::unordered_set<int>(languages[i].begin(), languages[i].end());
        }
        
        for (const auto& f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            
            for (const auto& lang : userLanguages[u]) {
                if (userLanguages[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }
            
            if (!canCommunicate) {
                needToLearn.insert(u);
                needToLearn.insert(v);
            }
        }
        
        std::unordered_map<int, int> languageCount;
        for (int u : needToLearn) {
            for (int lang : userLanguages[u]) {
                languageCount[lang]++;
            }
        }
        
        int maxKnownLang = 0;
        for (const auto& pair : languageCount) {
            maxKnownLang = std::max(maxKnownLang, pair.second);
        }
        
        return needToLearn.size() - maxKnownLang;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/>maximum length of subarray with positive product</a></strong></summary>

```cpp
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int maxLength = 0;
        int positiveLen = 0, negativeLen = 0;
        
        for (int num : nums) {
            if (num == 0) {
                positiveLen = 0;
                negativeLen = 0;
            } else if (num > 0) {
                positiveLen++;
                if (negativeLen > 0) negativeLen++;
            } else {
                int temp = positiveLen;
                positiveLen = (negativeLen > 0) ? negativeLen + 1 : 0;
                negativeLen = temp + 1;
            }
            maxLength = max(maxLength, positiveLen);
        }
        
        return maxLength;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/can-i-win/>can i win</a></strong></summary>

```cpp
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) return true;
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if (sum < desiredTotal) return false;
        
        unordered_map<int, bool> memo;
        vector<bool> used(maxChoosableInteger + 1, false);
        
        return canWin(desiredTotal, used, memo, maxChoosableInteger);
    }
    
    bool canWin(int total, vector<bool>& used, unordered_map<int, bool>& memo, int maxChoosableInteger) {
        int key = getKey(used);
        if (memo.find(key) != memo.end()) return memo[key];
        
        for (int i = 1; i <= maxChoosableInteger; ++i) {
            if (!used[i]) {
                used[i] = true;
                if (total - i <= 0 || !canWin(total - i, used, memo, maxChoosableInteger)) {
                    used[i] = false;
                    memo[key] = true;
                    return true;
                }
                used[i] = false;
            }
        }
        
        memo[key] = false;
        return false;
    }
    
    int getKey(const vector<bool>& used) {
        int key = 0;
        for (bool u : used) {
            key = (key << 1) | u;
        }
        return key;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/two-city-scheduling/>two city scheduling</a></strong></summary>

```cpp
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2;
        int totalCost = 0;
        
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });
        
        for (int i = 0; i < n; ++i) {
            totalCost += costs[i][0];  
        }
        for (int i = n; i < 2 * n; ++i) {
            totalCost += costs[i][1];
        }
        
        return totalCost;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/>best time to buy and sell stock with transaction fee</a></strong></summary>

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int cash = 0;  
        int hold = -prices[0];  
        
        for (int i = 1; i < n; ++i) {
            cash = max(cash, hold + prices[i] - fee);
            hold = max(hold, cash - prices[i]);      
        }
        
        return cash;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/>divide array in sets of k consecutive numbers</a></strong></summary>

```cpp
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;
        
        map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        for (auto& [num, freq] : count) {
            if (freq > 0) {
                int needed = freq;
                for (int i = 0; i < k; ++i) {
                    if (count[num + i] < needed) {
                        return false;
                    }
                    count[num + i] -= needed;
                }
            }
        }
        
        return true;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/determine-if-two-strings-are-close/>determine if two strings are close</a></strong></summary>

```cpp
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        vector<int> freq1(26, 0), freq2(26, 0);
        vector<int> char1(26, 0), char2(26, 0);

        for (char c : word1) {
            freq1[c - 'a']++;
            char1[c - 'a'] = 1;
        }
        
        for (char c : word2) {
            freq2[c - 'a']++;
            char2[c - 'a'] = 1;
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2 && char1 == char2;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/>smallest subsequence of distinct characters</a></strong></summary>

```cpp
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26, 0);  
        vector<bool> seen(26, false);  
        stack<char> st;  
        
        for (int i = 0; i < s.size(); ++i) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            
            if (seen[c - 'a']) continue; 
            
            while (!st.empty() && st.top() > c && lastIndex[st.top() - 'a'] > i) {
                seen[st.top() - 'a'] = false;  
                st.pop();  
            }
            
            st.push(c);  
            seen[c - 'a'] = true;  
        }
        
        string result;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        
        return result;
    }
};
```
</details>