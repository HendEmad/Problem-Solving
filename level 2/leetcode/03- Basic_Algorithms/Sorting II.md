<details>
  <summary><strong><a href=https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/>Widest Vertical Area Between Two Points Containing No Points</a></strong></summary>

```cpp
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xCoordinates;
        for (const auto& point : points) 
            xCoordinates.push_back(point[0]);
        

        sort(xCoordinates.begin(), xCoordinates.end());
        int maxWidth = 0;
        for (int i = 1; i < xCoordinates.size(); ++i) 
            maxWidth = max(maxWidth, xCoordinates[i] - xCoordinates[i - 1]);
        
        return maxWidth;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/sort-the-matrix-diagonally/description/>Sort the Matrix Diagonally</a></strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        for (int i = 0; i < m; i++) {
            vector<int> diagonal;
            int row = i, col = 0;
            while (row < m && col < n) {
                diagonal.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(diagonal.begin(), diagonal.end());
            
            row = i, col = 0;
            int index = 0;
            while (row < m && col < n) {
                mat[row][col] = diagonal[index++];
                row++;
                col++;
            }
        }
        
        for (int j = 1; j < n; j++) {
            vector<int> diagonal;
            int row = 0, col = j;
            while (row < m && col < n) {
                diagonal.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(diagonal.begin(), diagonal.end());
            
            row = 0, col = j;
            int index = 0;
            while (row < m && col < n) {
                mat[row][col] = diagonal[index++];
                row++;
                col++;
            }
        }
        
        return mat;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/>Minimize Maximum Pair Sum in Array</a></strong></summary>

```cpp
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxPairSum = 0;
        int n = nums.size();
        
        for (int i = 0; i < n / 2; i++) 
            maxPairSum = max(maxPairSum, nums[i] + nums[n - 1 - i]);
        
        return maxPairSum;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/>All Elements in Two Binary Search Trees</a></strong></summary>

```cpp
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& result) {
        if (!root) 
            return;
            
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
    
    vector<int> mergeSortedVectors(vector<int>& list1, vector<int>& list2) {
        vector<int> merged;
        int i = 0, j = 0;
        
        while (i < list1.size() && j < list2.size()) {
            if (list1[i] < list2[j]) {
                merged.push_back(list1[i]);
                i++;
            } else {
                merged.push_back(list2[j]);
                j++;
            }
        }
        
        while (i < list1.size()) {
            merged.push_back(list1[i]);
            i++;
        }
        
        while (j < list2.size()) {
            merged.push_back(list2[j]);
            j++;
        }
        
        return merged;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1, list2;

        inorder(root1, list1);
        inorder(root2, list2);
        return mergeSortedVectors(list1, list2);
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/arithmetic-subarrays/description/>Arithmetic Subarrays</a></strong></summary>

```cpp
class Solution {
public:
    bool isArithmetic(vector<int>& subarray) {
        sort(subarray.begin(), subarray.end());
        int diff = subarray[1] - subarray[0];
        
        for (int i = 2; i < subarray.size(); i++) 
            if (subarray[i] - subarray[i - 1] != diff) 
                return false;
        
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result;
        
        for (int i = 0; i < l.size(); i++) {
            vector<int> subarray(nums.begin() + l[i], nums.begin() + r[i] + 1);
            result.push_back(isArithmetic(subarray));
        }
        
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/>Maximum Number of Coins You Can Get</a></strong></summary>

```cpp
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
        
        int n = piles.size() / 3;
        int maxCoins = 0;
        
        for (int i = 1; i < 2 * n; i += 2) 
            maxCoins += piles[i];
        
        return maxCoins;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/pancake-sorting/description/>Pancake Sorting</a></strong></summary>

```cpp
class Solution {
public:
    void flip(vector<int>& arr, int k) {
        reverse(arr.begin(), arr.begin() + k);
    }
    
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();
        
        for (int currSize = n; currSize > 1; --currSize) {
            int maxIdx = max_element(arr.begin(), arr.begin() + currSize) - arr.begin();
            
            if (maxIdx == currSize - 1) 
                continue;
            
            if (maxIdx > 0) {
                flip(arr, maxIdx + 1);
                result.push_back(maxIdx + 1); 
            }
            
            flip(arr, currSize);
            result.push_back(currSize);  
        }
        
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/maximum-ice-cream-bars/description/>Maximum Ice Cream Bars</a></strong></summary>

```cpp
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        const int MAX_COST = 100000;
        vector<int> count(MAX_COST + 1, 0);
        
        for (int cost : costs) 
            count[cost]++;
        
        int iceCreams = 0;
        
        for (int i = 1; i <= MAX_COST; ++i) {
            if (count[i] == 0) 
                continue; 
            
            int barsToBuy = min(count[i], coins / i);
            iceCreams += barsToBuy;
            coins -= barsToBuy * i;
            
            if (coins < i) 
                break;
        }
        
        return iceCreams;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/rearrange-words-in-a-sentence/description/>Rearrange Words in a Sentence</a></strong></summary>

```cpp
class Solution {
public:
    string arrangeWords(string text) {
        text[0] = tolower(text[0]);
        stringstream ss(text);
        vector<pair<string, int>> words;
        string word;
        int index = 0;
        
        while (ss >> word) {
            words.push_back({word, index++});
        }

        stable_sort(words.begin(), words.end(), 
        [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.first.size() == b.first.size()) 
                return a.second < b.second;
            return a.first.size() < b.first.size();
        });

        string result;
        for (int i = 0; i < words.size(); ++i) {
            if (i > 0) result += " ";
            result += words[i].first;
        }

        result[0] = toupper(result[0]);
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/>Range Sum of Sorted Subarray Sums</a></strong></summary>

```cpp
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        vector<int> subarraySums;

        for (int i = 0; i < n; ++i) {
            int currentSum = 0;
            for (int j = i; j < n; ++j) {
                currentSum += nums[j];
                subarraySums.push_back(currentSum);
            }
        }

        sort(subarraySums.begin(), subarraySums.end());

        long long result = 0;
        for (int i = left - 1; i < right; ++i) 
            result = (result + subarraySums[i]) % MOD;

        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/>Largest Submatrix With Rearrangements</a></strong></summary>

```cpp
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int i = 1; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (matrix[i][j] == 1) 
                    matrix[i][j] += matrix[i - 1][j];

        
        int maxArea = 0;
        
        for (int i = 0; i < m; ++i) {
            vector<int> sortedRow = matrix[i];
            sort(sortedRow.begin(), sortedRow.end(), greater<int>());
            
            for (int j = 0; j < n; ++j) {
                int area = sortedRow[j] * (j + 1);
                maxArea = std::max(maxArea, area);
            }
        }
        
        return maxArea;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/the-k-strongest-values-in-an-array/description/>The k Strongest Values in an Array</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int median = arr[(n - 1) / 2];

        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int strengthA = abs(a - median);
            int strengthB = abs(b - median);
            if (strengthA == strengthB) 
                return a > b; 

            return strengthA > strengthB;
        });

        return vector<int>(arr.begin(), arr.begin() + k);
    }
};
```
</details>