<details>
  <summary><strong><a href=https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/>Maximum Depth of N-ary Tree</a></strong></summary>

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root)  
            return 0;
        
        int depth = 0;
        for (Node* child : root->children) 
            depth = max(depth, maxDepth(child));
        
        return depth + 1;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/employee-importance/>employee importance</a></strong></summary>

```cpp
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> employeeMap;
        for (auto employee : employees) 
            employeeMap[employee->id] = employee;
        
        return dfs(employeeMap, id);
    }
    
private:
    int dfs(unordered_map<int, Employee*>& employeeMap, int id) {
        Employee* employee = employeeMap[id];
        int totalImportance = employee->importance;
        for (int subordinate : employee->subordinates) 
            totalImportance += dfs(employeeMap, subordinate);
        
        return totalImportance;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/cousins-in-binary-tree/>cousins in binary tree</a></strong></summary>

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        pair<TreeNode*, int> infoX = findParentAndDepth(root, nullptr, x, 0);
        pair<TreeNode*, int> infoY = findParentAndDepth(root, nullptr, y, 0);
        
        return (infoX.first != infoY.first && infoX.second == infoY.second);
    }

private:
    pair<TreeNode*, int> findParentAndDepth(TreeNode* node, TreeNode* parent, int value, int depth) {
        if (!node) 
            return {nullptr, -1};
        
        if (node->val == value) 
            return {parent, depth};
        
        pair<TreeNode*, int> left = findParentAndDepth(node->left, node, value, depth + 1);
        if (left.first) 
            return left;
        
        return findParentAndDepth(node->right, node, value, depth + 1);
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/>find a corresponding node of a binary tree in a clone of that tree</a></strong></summary>

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original) 
            return nullptr;
        
        if (original == target) 
            return cloned;
        
        TreeNode* leftResult = getTargetCopy(original->left, cloned->left, target);
        if (leftResult) 
            return leftResult;
        
        return getTargetCopy(original->right, cloned->right, target);
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/minesweeper/>minesweeper</a></strong></summary>

```cpp
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        int x = click[0], y = click[1];
        
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        
        dfs(board, x, y, m, n);
        return board;
    }

private:
    void dfs(vector<vector<char>>& board, int x, int y, int m, int n) {
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'E')
            return;
        
        int mines = countMines(board, x, y, m, n);
        if (mines > 0) {
            board[x][y] = '0' + mines;
            return;
        }
        
        board[x][y] = 'B';
        for (int dx = -1; dx <= 1; ++dx) 
            for (int dy = -1; dy <= 1; ++dy) 
                if (dx != 0 || dy != 0) 
                    dfs(board, x + dx, y + dy, m, n);
    }
    
    int countMines(vector<vector<char>>& board, int x, int y, int m, int n) {
        int mines = 0;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'M') 
                    ++mines;
            }
        }

        return mines;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/jump-game-iii/>jump game iii</a></strong></summary>

```cpp
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        return dfs(arr, start, visited);
    }

private:
    bool dfs(vector<int>& arr, int index, vector<bool>& visited) {
        if (index < 0 || index >= arr.size() || visited[index]) 
            return false;
        
        if (arr[index] == 0) 
            return true;
        
        visited[index] = true;
        bool canReachLeft = dfs(arr, index - arr[index], visited);
        bool canReachRight = dfs(arr, index + arr[index], visited);
        
        return canReachLeft || canReachRight;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/>Maximum Level Sum of a Binary Tree</a></strong></summary>

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) 
            return 0;

        queue<TreeNode*> q;
        q.push(root);

        int maxSum = INT_MIN, maxLevel = 1, currentLevel = 1;

        while (!q.empty()) {
            int levelSum = 0;
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                levelSum += node->val;

                if (node->left) 
                    q.push(node->left);
                
                if (node->right) 
                    q.push(node->right);
            }

            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = currentLevel;
            }

            ++currentLevel;
        }

        return maxLevel;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/>N-ary Tree Level Order Traversal</a></strong></summary>

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) 
            return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop();

                currentLevel.push_back(node->val);
                for (Node* child : node->children) 
                    q.push(child);
            }

            result.push_back(currentLevel);
        }

        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/>Smallest Subtree with all the Deepest Nodes</a></strong></summary>

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }

private:
    pair<TreeNode*, int> dfs(TreeNode* node) {
        if (!node) 
            return {nullptr, 0};

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        if (left.second > right.second) {
            return {left.first, left.second + 1};
        } else if (left.second < right.second) {
            return {right.first, right.second + 1};
        } else {
            return {node, left.second + 1};
        }
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description/>Lexicographically Smallest String After Applying Operations</a></strong></summary>

```cpp
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> visited;
        string result = s;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            string current = q.front();
            q.pop();
            result = min(result, current);

            string added = addToOddIndices(current, a);
            if (!visited.count(added)) {
                visited.insert(added);
                q.push(added);
            }

            string rotated = rotateString(current, b);
            if (!visited.count(rotated)) {
                visited.insert(rotated);
                q.push(rotated);
            }
        }

        return result;
    }

private:
    string addToOddIndices(string s, int a) {
        for (int i = 1; i < s.size(); i += 2) {
            s[i] = (s[i] - '0' + a) % 10 + '0';
        }
        return s;
    }

    string rotateString(string s, int b) {
        int n = s.size();
        b %= n;
        return s.substr(n - b) + s.substr(0, n - b);
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/shortest-path-in-binary-matrix/description/>Shortest Path in Binary Matrix</a></strong></summary>

```cpp
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) 
            return -1;

        vector<vector<int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
        };

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            int distance = grid[x][y];

            if (x == n - 1 && y == n - 1) 
                return distance;

            for (const auto& dir : directions) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    grid[nx][ny] = distance + 1;
                    q.push({nx, ny});
                }
            }
        }

        return -1;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/description/>Check if There is a Valid Path in a Grid</a></strong></summary>

```cpp
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<pair<int, int>>> directions = {
            {}, 
            {{0, -1}, {0, 1}}, 
            {{-1, 0}, {1, 0}}, 
            {{0, -1}, {1, 0}}, 
            {{0, 1}, {1, 0}}, 
            {{0, -1}, {-1, 0}}, 
            {{0, 1}, {-1, 0}}
        };
        
        function<bool(int, int)> dfs = [&](int x, int y) {
            if (x == m - 1 && y == n - 1) return true;
            visited[x][y] = true;
            for (auto& dir : directions[grid[x][y]]) {
                int nx = x + dir.first, ny = y + dir.second;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) 
                    for (auto& back : directions[grid[nx][ny]]) 
                        if (nx + back.first == x && ny + back.second == y) 
                            if (dfs(nx, ny)) 
                                return true;
            }
            return false;
        };
        
        return dfs(0, 0);
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/>Pseudo-Palindromic Paths in a Binary Tree</a></strong></summary>

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* node, int count) {
            if (!node) 
                return 0;
            
            count ^= (1 << node->val);
            
            if (!node->left && !node->right) {
                return (count & (count - 1)) == 0 ? 1 : 0;
            }
            
            return dfs(node->left, count) + dfs(node->right, count);
        };
        
        return dfs(root, 0);
    }
};
```