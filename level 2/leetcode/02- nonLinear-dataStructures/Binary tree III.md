<details>
<summary><strong><a href = "https://leetcode.com/problems/find-duplicate-subtrees/description/">652. Find Duplicate Subtrees</a></strong></summary>

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
private:
    vector<pair<TreeNode*, vector<int>>> treeStructures;

    void traverseAndCollect(TreeNode* node, vector<int>& values) {
        if (!node) {
            values.push_back(-201); // Special marker for null nodes
            return;
        }

        values.push_back(node->val);
        traverseAndCollect(node->left, values);
        traverseAndCollect(node->right, values);
    }
    
    void exploreTree(TreeNode* node) {
        if (!node)
            return;

        vector<int> values;
        traverseAndCollect(node, values);
        treeStructures.push_back({node, values});
        exploreTree(node->left);
        exploreTree(node->right);
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        exploreTree(root);

        vector<TreeNode*> duplicates;
        set<vector<int>> seen;

        for (int i = 0; i < treeStructures.size(); i++) {
            for (int j = i + 1; j < treeStructures.size(); j++) {
                if (treeStructures[i].second == treeStructures[j].second && seen.find(treeStructures[i].second) == seen.end()) {
                    duplicates.push_back(treeStructures[i].first);
                    seen.insert(treeStructures[i].second);
                    break;
                }
            }
        }

        return duplicates;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/add-one-row-to-tree/description/">623. Add One Row to Tree</a></strong></summary>

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
    void dfs(TreeNode* root, int currentDepth, int targetDepth, int val) {
        if (root == nullptr) return;

        if (currentDepth == targetDepth - 1) {
            TreeNode* leftSubTree = root->left;
            TreeNode* rightSubTree = root->right;

            TreeNode* leftNewNode = new TreeNode(val);
            TreeNode* rightNewNode = new TreeNode(val);

            root->left = leftNewNode;
            root->right = rightNewNode;

            leftNewNode->left = leftSubTree;
            rightNewNode->right = rightSubTree;

            return;
        }

        dfs(root->left, currentDepth + 1, targetDepth, val);
        dfs(root->right, currentDepth + 1, targetDepth, val);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }

        dfs(root, 1, depth, val);
        return root;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/">958. Check Completeness of a Binary Tree</a></strong></summary>

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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root){return false;}
        q.push(root);
        bool end = false;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();

            if(current->left){
                if(end){return false;}
                q.push(current->left);
            }

            else
                end = true;

            if(current->right){
                if(end)
                    return false;

                q.push(current->right);
            }

            else 
                end = true;
        }
        return true;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/even-odd-tree/description/">1609. Even Odd Tree</a></strong></summary>

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
    bool isEvenOddTree(TreeNode* root) {
        if(root==NULL) 
            return false;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int c=0;
        while(!q.empty()){
            int size = q.size();
            vector<int> check;
            for(int i = 0; i < size ; i++){
                TreeNode* node = q.front();
                q.pop();
         
                if(c % 2 != 0 && node -> val % 2 != 0) 
                    return false;
                
                if(c % 2 == 0 && node-> val % 2 == 0) 
                    return false;
                
                check.push_back(node->val);
                if(node-> left != NULL) 
                    q.push(node-> left);

                if(node-> right != NULL) 
                    q.push(node-> right);
            }

            if(c % 2 == 0)
                for(int i = 0; i < check.size() - 1; i++)
                    if(check[i] >= check[i+1]) 
                        return false;
                
            else
                for(int i=0;i<check.size()-1;i++)
                    if(check[i]<=check[i+1]) 
                        return false;
            
            c++;
        }
        return true;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/balance-a-binary-search-tree/description/">1382. Balance a Binary Search Tree</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> nums;
    
    void inorderTraversal(TreeNode* root) {
        if (!root) 
            return;
        
        inorderTraversal(root->left);  
        nums.push_back(root->val);     
        inorderTraversal(root->right); 
    }

    TreeNode* sortedArrayToBST(int start, int end) {
        if (start > end) 
            return nullptr; 
        
        int mid = start + (end - start) / 2; 
        TreeNode* node = new TreeNode(nums[mid]);  
        node->left = sortedArrayToBST(start, mid - 1); 
        node->right = sortedArrayToBST(mid + 1, end);  
        return node;
    }
    
    
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraversal(root);  
        return sortedArrayToBST(0, nums.size() - 1);  
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/flip-equivalent-binary-trees/description/">951. Flip Equivalent Binary Trees</a></strong></summary>

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
    bool f(TreeNode* root1, TreeNode* root2){
        if(root1==NULL && root2!=NULL)
            return false;
        if(root2==NULL && root1!=NULL)
            return false;
        if(root1==NULL && root2==NULL)
            return true;

        if(root1->val!=root2->val)
            return false;

        bool a=f(root1->left,root2->left);
        bool b=f(root1->right,root2->right);
        bool c=f(root1->left,root2->right);
        bool d=f(root1->right,root2->left);
        return (c&&d) || (a&&b);

    }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return f(root1,root2);
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/">671. Second Minimum Node In a Binary Tree</a></strong></summary>

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
    void inorder(TreeNode* root, set<int>& unique_vals) {
        if (root == nullptr) 
            return;
            
        inorder(root->left, unique_vals);
        unique_vals.insert(root->val);
        inorder(root->right, unique_vals);
    }

    int findSecondMinimumValue(TreeNode* root) {
    set<int> unique_vals;
    inorder(root, unique_vals);
        
    if(unique_vals.size() < 2) 
        return -1;
        
    auto it = unique_vals.begin();
    ++it;
    
    return *it;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/special-binary-string/description/">761. Special Binary String</a></strong></summary>

```cpp
class Solution {
public:
    string makeLargestSpecial(string s) {
        if(s.length()==0)
            return "";

        vector<string> ans; 
        int count=0,i=0;

        for(int j=0;j<s.size();j++){
            if(s[j] == '1')
                count++;
            else
                count--;
            if(count==0){
                ans.push_back('1' + makeLargestSpecial(s.substr(i+1,j-i-1)) + '0');
                i = j+1;
            }
        }

        sort(ans.begin(),ans.end(),greater<string>());
        string finalString = "";
        for(i=0;i<ans.size();i++)
            finalString += ans[i];
        
        return finalString;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/maximum-number-of-balloons/description/">1189. Maximum Number of Balloons</a></strong></summary>

```cpp
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>freq;
        int count=0;
        for(char c : text)
            freq[c]++;

        int minfreq=min({freq['b'],freq['a'],freq['l']/2,freq['o']/2,freq['n']});

        return minfreq;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/description/">1104. Path In Zigzag Labelled Binary Tree</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = 0, a = label;
        while(a > 0){
            a /= 2;
            level++;
        }

        vector<int> ans(level);
        ans[level - 1] = label;
        for(int i = level - 1 ; i > 0 ; i--){
            int maxi = pow(2,i) - 1;
            int mini = pow(2,i-1);
            int parent = maxi + mini - label/2;
            ans[i - 1] = parent;
            label = parent;
        }

        return ans;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/unique-binary-search-trees/description/">96. Unique Binary Search Trees</a></strong></summary>

```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int left = 0; left < i; left++) {
                int right = i - left - 1;
                dp[i] += dp[left] * dp[right];
            }
        }
        return dp[n];
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/n-th-tribonacci-number/description/">1137. N-th Tribonacci Number</a></strong></summary>

```cpp
class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)
            return 0;

        else if(n == 1 || n == 2)
            return 1;

        int T0 = 0, T1 = 1, T2 = 1;
        int current;

        for(int i = 3; i <= n; i++){
            current = T0 + T1 + T2;
            T0 = T1;
            T1 = T2;
            T2 = current;
        }
        return current;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/all-possible-full-binary-trees/description/">894. All Possible Full Binary Trees</a></strong></summary>

```cpp
// Brute force solution 
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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n == 0)
            return {};
        
        if(n == 1)
            return {new TreeNode(0)};
        
        vector <TreeNode*> res;
        for(int i = 1; i < n; i+= 2) {
            vector <TreeNode*> left_subtree = allPossibleFBT(i);
            vector <TreeNode*> right_subtree = allPossibleFBT(n - i - 1);

            for(auto left : left_subtree) {
                for(auto right : right_subtree) {
                    TreeNode* root = new TreeNode(0);
                    root -> left = left;
                    root -> right = right;
                    res.emplace_back(root);
                }
            }
        }
        return res;
    }
};

// Optimized solution using memoization 
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>> memo;
        if(memo.find(n) != memo.end()) 
            return memo[n];

        if(n == 0)
            return {};
        if(n == 1)
            return {new TreeNode(0)};
        
        vector <TreeNode*> res;
        for(int i = 1; i < n; i+= 2) {
            vector <TreeNode*> left_subtree = allPossibleFBT(i);
            vector <TreeNode*> right_subtree = allPossibleFBT(n - i - 1);

            for(auto left : left_subtree) {
                for(auto right : right_subtree) {
                    TreeNode* root = new TreeNode(0);
                    root -> left = left;
                    root -> right = right;
                    res.emplace_back(root);
                }
            }
        }
        return res;
    }
};
```
</details>