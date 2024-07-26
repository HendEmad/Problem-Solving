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

        // Check if the current depth is the one just above the target depth
        if (currentDepth == targetDepth - 1) {
            TreeNode* leftSubTree = root->left;
            TreeNode* rightSubTree = root->right;

            // Create new nodes to be inserted
            TreeNode* leftNewNode = new TreeNode(val);
            TreeNode* rightNewNode = new TreeNode(val);

            // Insert the new nodes
            root->left = leftNewNode;
            root->right = rightNewNode;

            // Attach the original subtrees to the new nodes
            leftNewNode->left = leftSubTree;
            rightNewNode->right = rightSubTree;

            return;
        }

        // Continue to traverse the tree
        dfs(root->left, currentDepth + 1, targetDepth, val);
        dfs(root->right, currentDepth + 1, targetDepth, val);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // Special case: if the new row needs to be added at the root
        if (depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }

        // Use DFS to add the row at the correct depth
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
            else{end = true;}
            if(current->right){
                if(end){return false;}
                q.push(current->right);
            }
            else{end = true;}
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
        if(root==NULL) return false;
        queue<TreeNode*> q;
        q.push(root);
        int c=0;
        while(!q.empty()){
            int size = q.size();
            vector<int> check;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(c%2!=0&&node->val%2!=0) return false;
                if(c%2==0&&node->val%2==0) return false;
                check.push_back(node->val);
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            if(c%2==0){
                for(int i=0;i<check.size()-1;i++){
                    if(check[i]>=check[i+1]) return false;
                }
            }
            else{
                for(int i=0;i<check.size()-1;i++){
                    if(check[i]<=check[i+1]) return false;
                }
            }
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
    // Vector to store the values of nodes in sorted order
    vector<int> nums;
    
    //  function to perform inorder traversal and store the values in the vector
    void inorderTraversal(TreeNode* root) {
        if (!root) return;
        inorderTraversal(root->left);  
        nums.push_back(root->val);     
        inorderTraversal(root->right); 
    }

    // function to convert a sorted array to a balanced BST
    TreeNode* sortedArrayToBST(int start, int end) {
        if (start > end) return nullptr;  // Base case: no elements to construct the subtree
        int mid = start + (end - start) / 2;  // Find the middle element
        TreeNode* node = new TreeNode(nums[mid]);  // Create a new node with the middle element
        node->left = sortedArrayToBST(start, mid - 1);  // Recursively construct the left subtree
        node->right = sortedArrayToBST(mid + 1, end);   // Recursively construct the right subtree
        return node;  // Return the constructed subtree
    }
    
    
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraversal(root);  // Step 1: Perform inorder traversal to get sorted node values
        return sortedArrayToBST(0, nums.size() - 1);  // Step 2: Construct a balanced BST from the sorted values
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
        if (root == nullptr) return;
        
        inorder(root->left, unique_vals);
        unique_vals.insert(root->val);
        inorder(root->right, unique_vals);
    }
    int findSecondMinimumValue(TreeNode* root) {
     set<int> unique_vals;
        inorder(root, unique_vals);
        
        // If there are less than 2 unique values, return -1
        if (unique_vals.size() < 2) return -1;
        
        // Return the second smallest element
        auto it = unique_vals.begin();
        ++it; // Move iterator to the second element
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
            return ""; //return null string if size is zero

        vector<string> ans; //list to store all current special substrings
        int count=0,i=0; //keep track of special substring starting index using "i" and 
                         //"count" to keep the track of special substring is over or not

        for(int j=0;j<s.size();j++){
            if(s[j] == '1')
                count++;
            else
                count--;
            if(count==0){
                //call recursively using mid special substring
                ans.push_back('1' + makeLargestSpecial(s.substr(i+1,j-i-1)) + '0');
                i = j+1;
            }
        }
        //sort current substring stored list to fulfill the question demand
        sort(ans.begin(),ans.end(),greater<string>());
        string finalString = "";
        for(i=0;i<ans.size();i++){
            finalString += ans[i];
        }
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
            // To find biggest value in prev level 
            int maxi = pow(2,i) - 1;
            // To find smallest value in prev level
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