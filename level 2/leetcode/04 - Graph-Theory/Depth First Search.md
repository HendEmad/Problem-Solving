<details>
  <summary><strong><a href=https://leetcode.com/problems/range-sum-of-bst/description/>Range Sum of BST</a></strong></summary>

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) 
            return 0;

        int sum = 0;
        if (root->val >= low && root->val <= high) 
            sum += root->val;
        
        if (root->val > low) 
            sum += rangeSumBST(root->left, low, high);
        
        if (root->val < high) 
            sum += rangeSumBST(root->right, low, high);
        
        return sum;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/increasing-order-search-tree/description/>Increasing Order Search Tree</a></strong></summary>

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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        TreeNode* current = dummy;
        
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) 
                return;
            
            inorder(node->left);
            current->right = new TreeNode(node->val);
            current = current->right;
            inorder(node->right);
        };
        
        inorder(root);
        return dummy->right;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/leaf-similar-trees/description/>Leaf-Similar Trees</a></strong></summary>

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        auto getLeaves = [](TreeNode* root) {
            vector<int> leaves;
            function<void(TreeNode*)> dfs = [&](TreeNode* node) {
                if (!node) 
                    return;

                if (!node->left && !node->right) 
                    leaves.push_back(node->val);
                
                dfs(node->left);
                dfs(node->right);
            };
            dfs(root);
            return leaves;
        };
        
        return getLeaves(root1) == getLeaves(root2);
    }
};
```
</details>


<details>
  <summary><strong><a href=https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/>Maximum Difference Between Node and Ancestor</a></strong></summary>

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
    int maxAncestorDiff(TreeNode* root) {
        function<int(TreeNode*, int, int)> dfs = [&](TreeNode* node, int minVal, int maxVal) {
            if (!node) 
                return maxVal - minVal;
            
            minVal = min(minVal, node->val);
            maxVal = max(maxVal, node->val);
            return max(dfs(node->left, minVal, maxVal), dfs(node->right, minVal, maxVal));
        };
        return dfs(root, root->val, root->val);
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/flood-fill/description/>Flood Fill</a></strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size(), cols = image[0].size();
        int originalColor = image[sr][sc];
        if (originalColor == color) return image;

        function<void(int, int)> dfs = [&](int r, int c) {
            if (r < 0 || c < 0 || r >= rows || c >= cols || image[r][c] != originalColor) 
                return;
            
            image[r][c] = color;
            dfs(r - 1, c);
            dfs(r + 1, c);
            dfs(r, c - 1);
            dfs(r, c + 1);
        };

        dfs(sr, sc);
        return image;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/binary-tree-paths/description/>Binary Tree Paths</a></strong></summary>

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;

        function<void(TreeNode*, string)> dfs = [&](TreeNode* node, string path) {
            if (!node) 
                return;
            
            if (!path.empty()) 
                path += "->";
            
            path += to_string(node->val);

            if (!node->left && !node->right) {
                paths.push_back(path);
                return;
            }

            dfs(node->left, path);
            dfs(node->right, path);
        };

        dfs(root, "");
        return paths;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/>Minimum Distance Between BST Nodes</a></strong></summary>

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
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX, prev = -1;

        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) 
                return;
            
            inorder(node->left);
            if (prev != -1) minDiff = min(minDiff, node->val - prev);
            prev = node->val;
            inorder(node->right);
        };

        inorder(root);
        return minDiff;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/deepest-leaves-sum/description/>Deepest Leaves Sum</a></strong></summary>

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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            sum = 0;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) 
                    q.push(node->left);
                
                if (node->right) 
                    q.push(node->right);
            }
        }

        return sum;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/binary-tree-tilt/description/>Binary Tree Tilt</a></strong></summary>

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
    int findTilt(TreeNode* root) {
        int totalTilt = 0;

        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) 
                return 0;
            
            int leftSum = dfs(node->left);
            int rightSum = dfs(node->right);
            totalTilt += abs(leftSum - rightSum);
            return leftSum + rightSum + node->val;
        };

        dfs(root);
        return totalTilt;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/balanced-binary-tree/description/>Balanced Binary Tree</a></strong></summary>

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
    bool isBalanced(TreeNode* root) {
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) 
                return 0;
            
            int leftHeight = dfs(node->left);
            if (leftHeight == -1) 
                return -1;
            
            int rightHeight = dfs(node->right);
            if (rightHeight == -1) 
                return -1;
            
            if (abs(leftHeight - rightHeight) > 1) 
                return -1;
            
            return max(leftHeight, rightHeight) + 1;
        };
        
        return dfs(root) != -1;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/description/>Sum of Nodes with Even-Valued Grandparent</a></strong></summary>

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
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        
        function<void(TreeNode*, TreeNode*, TreeNode*)> dfs = [&](TreeNode* node, TreeNode* parent, TreeNode* grandparent) {
            if (!node) 
                return;
            
            if (grandparent && grandparent->val % 2 == 0) 
                sum += node->val;
            
            dfs(node->left, node, parent);
            dfs(node->right, node, parent);
        };
        
        dfs(root, nullptr, nullptr);
        return sum;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/>Binary Search Tree to Greater Sum Tree</a></strong></summary>

```cpp
class Solution {
    int cumulativeSum = 0;
    
    void traverse(TreeNode* node) {
        if (!node) 
            return;
        
        traverse(node->right);
        cumulativeSum += node->val;
        node->val = cumulativeSum;
        traverse(node->left);
    }
    
public:
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        return root;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/>Number of Good Leaf Nodes Pairs</a></strong></summary>

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
    int countGoodPairs(TreeNode* node, int distance, vector<int>& depths) {
        if (!node) return 0;

        if (!node->left && !node->right) {
            depths = {1};
            return 0;
        }

        vector<int> leftDepths, rightDepths;
        int leftPairs = countGoodPairs(node->left, distance, leftDepths);
        int rightPairs = countGoodPairs(node->right, distance, rightDepths);

        int count = leftPairs + rightPairs;

        for (int l : leftDepths) 
            for (int r : rightDepths) 
                if (l + r <= distance) 
                    count++;

        for (int d : leftDepths) 
            if (d + 1 <= distance) 
                depths.push_back(d + 1);

        for (int d : rightDepths) 
            if (d + 1 <= distance) 
                depths.push_back(d + 1);

        return count;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        vector<int> depths;
        return countGoodPairs(root, distance, depths);
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/>Flatten a Multilevel Doubly Linked List</a></strong></summary>

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        Node* current = head;
        while (current) {
            if (current->child) {
                Node* next = current->next;
                Node* childHead = flatten(current->child);
                current->next = childHead;
                childHead->prev = current;
                current->child = nullptr;

                Node* tail = childHead;
                while (tail->next) 
                    tail = tail->next;

                if (next) {
                    tail->next = next;
                    next->prev = tail;
                }
            }

            current = current->next;
        }

        return head;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/time-needed-to-inform-all-employees/description/>Time Needed to Inform All Employees</a></strong></summary>

```cpp
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> tree(n);
        for (int i = 0; i < n; ++i) 
            if (manager[i] != -1) 
                tree[manager[i]].push_back(i);

        function<int(int)> dfs = [&](int employee) {
            int maxTime = 0;
            for (int subordinate : tree[employee]) 
                maxTime = max(maxTime, dfs(subordinate));

            return maxTime + informTime[employee];
        };

        return dfs(headID);
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/number-of-enclaves/description/>Number of Enclaves</a></strong></summary>

```cpp
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto dfs = [&](int i, int j, auto& dfs) {
            if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
                return;
            
            grid[i][j] = 0;
            dfs(i - 1, j, dfs);
            dfs(i + 1, j, dfs);
            dfs(i, j - 1, dfs);
            dfs(i, j + 1, dfs);
        };
        for (int i = 0; i < m; ++i) {
            dfs(i, 0, dfs);
            dfs(i, n - 1, dfs);
        }
        for (int j = 0; j < n; ++j) {
            dfs(0, j, dfs);
            dfs(m - 1, j, dfs);
        }
        int count = 0;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (grid[i][j] == 1) 
                    ++count;
        
        return count;
    }
};
```
</details>