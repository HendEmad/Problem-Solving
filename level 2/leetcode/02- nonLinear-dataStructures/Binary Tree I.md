<details>
  <summary><strong><a href = "https://leetcode.com/problems/n-ary-tree-preorder-traversal/">589.N-ary Tree Preorder Traversal</a></strong></summary>

  ```cpp
  class Solution {
public:
    vector <int> ans;
    void traverse(Node* root) {
        if(root == NULL) 
            return;
        ans.push_back(root -> val);
        for(int i = 0; i < root -> children.size(); i++) {
            traverse(root -> children[i]);
        }
    }

    vector<int> preorder(Node* root) {
        traverse(root);
        return ans;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/n-ary-tree-postorder-traversal/">590.N-ary Tree Postorder Traversal</a></strong></summary>

```cpp
class Solution {
public:
    vector <int> ans;
    void traverse(Node* root) {
        if(root == NULL)
            return;
        for(int i = 0; i < root -> children.size(); i++) {
            traverse(root -> children[i]);
        }
        ans.push_back(root -> val);
    }
    vector<int> postorder(Node* root) {
        traverse(root);
        return ans;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/search-in-a-binary-search-tree/">700.Search in a Binary Search Tree</a></strong></summary>

```cpp
class Solution {
public:

    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
            return NULL;
        if(root -> val == val)
            return root;
        if(val > root -> val)
            return searchBST(root -> right, val);
        else if(val < root -> val)
            return searchBST(root -> left, val);
        return root;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/">1022.Sum of Root To Leaf Binary Numbers</a></strong></summary>

```cpp
class Solution {
public:

    void trace(TreeNode* root, int& ans, int sum){
        if(root == NULL)
            return;
        sum = 2 * sum + root->val;  // shifting and adding up the new left child
        if(root -> left == NULL && root -> right == NULL){
            ans += sum;
            return;
        }
        if(root -> left) 
            trace(root-> left, ans, sum);
        if(root -> right)
            trace(root -> right, ans, sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        int sum = 0, ans = 0;
        trace(root, ans, sum);  
        return ans;  
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/univalued-binary-tree/">965.Univalued Binary Tree</a></strong></summary>

```cpp
class Solution {
    bool isUnival(TreeNode* node, int value) {
        // If the node is NULL, return true
        if (node == NULL) return true;
        // If the current node's value is not equal to the given value, return false
        if (node->val != value) return false;
        // Recursively check the left and right subtrees
        return isUnival(node->left, value) && isUnival(node->right, value);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        // If the tree is empty, it is considered uni-valued
        if (root == NULL) return true;
        // Helper function to recursively check if the tree is uni-valued
        return isUnival(root, root->val);
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/sum-of-left-leaves/">404.Sum of Left Leaves</a></strong></summary>

```cpp
class Solution {
    int sumOfLeftLeavesHelper(TreeNode* node, bool isLeft) {
        if (node == NULL) return 0;
        if (node->left == NULL && node->right == NULL && isLeft) 
            return node->val;

        int leftSum = sumOfLeftLeavesHelper(node->left, true);
        int rightSum = sumOfLeftLeavesHelper(node->right, false);
        return leftSum + rightSum;
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeavesHelper(root, false);
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/two-sum-iv-input-is-a-bst/">653.Two Sum IV - Input is a BST</a></strong></summary>

```cpp
class Solution {
    bool find(TreeNode* node, int k, unordered_set<int>& seen) {
        if (node == NULL) {
            return false;
        }
        
        if (seen.count(k - node->val)) {
            return true;
        }
        
        seen.insert(node->val);
        
        return find(node->left, k, seen) || find(node->right, k, seen);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return find(root, k, seen);
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/binary-tree-pruning/">814.Binary Tree Pruning</a></strong></summary>

```cpp
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL) return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->val == 1) return root;
        if (root->left == NULL && root->right == NULL) return NULL;
        return root;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/construct-string-from-binary-tree/">606.Construct String from Binary Tree</a></strong></summary>

```cpp
class Solution {
    private :
    void create(TreeNode* root , string &st){
        if(!root){
            return ;
        }
        else{
            string t = to_string(root -> val);
            st += t;
            if(!root->left && !root->right){
                return ;
            }
            st+="(";
            create(root -> left , st);
            st+=")";
            if(root->right){
                st+="(";
                create(root -> right , st);
                st+=")";
            }
        }
    }
public:
    string tree2str(TreeNode* root) {
        string res = "";
        create(root , res);
        return res;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/">1008.Construct Binary Search Tree from Preorder Traversal</a></strong></summary>

```cpp
class Solution {
public:
    TreeNode* solve(vector<int>p,int mini,int maxi,int&i){
        if(i>=p.size()){
            return NULL;
        }

        if(p[i]<mini || p[i]>maxi){
            return NULL;
        }

        TreeNode* root=new TreeNode(p[i++]);
        root->left=solve(p,mini,root->val,i);
        root->right=solve(p,root->val,maxi,i);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(preorder,INT_MIN,INT_MAX,i);
        
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/insert-into-a-binary-search-tree/">701.Insert into a Binary Search Tree</a></strong></summary>

```cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int d) {
        if(root == NULL){
            return new TreeNode(d);
        }
        TreeNode* temp = new TreeNode(d);
        TreeNode* ans = root;
        while(root!=NULL){
            if(root->val < d){
                if(root->right)
                    root = root->right;
                else {
                    root->right = temp;
                    break;
                    }
            }else{
                if(root -> left)
                    root = root->left;
                else {
                    root->left = temp;
                    break;
                    }
            }
        }
        return ans;

    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/">1261.Find Elements in a Contaminated Binary Tree</a></strong></summary>

```cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int d) {
        if(root == NULL){
            return new TreeNode(d);
        }
        TreeNode* temp = new TreeNode(d);
        TreeNode* ans = root;
        while(root!=NULL){
            if(root->val < d){
                if(root->right)
                    root = root->right;
                else {
                    root->right = temp;
                    break;
                    }
            }else{
                if(root -> left)
                    root = root->left;
                else {
                    root->left = temp;
                    break;
                    }
            }
        }
        return ans;

    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/delete-leaves-with-a-given-value/">1325.Delete Leaves With a Given Value</a></strong></summary>

```cpp
class Solution {
public:
    void remove(TreeNode * root,int t){
        if(root==NULL){
            return;
        }
        else{
            remove(root->left,t);
            remove(root->right,t);
            if(root->left!=NULL){
                if(root->left->val==t){
                    if(root->left->left==NULL && root->left->right==NULL){
                        root->left=NULL;
                    }
                }
            }
                        if(root->right!=NULL){
                if(root->right->val==t){
                    if(root->right->left==NULL && root->right->right==NULL){
                        root->right=NULL;
                    }
                }
            }
            return;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        remove(root,target);
        if(root->val==target && root->left==NULL && root->right==NULL) return NULL;
        return root;
        
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/find-mode-in-binary-search-tree/">501.Find Mode in Binary Search Tree</a></strong></summary>

```cpp
class Solution {
public:
void inorder(TreeNode* root,unordered_map<int,int>&mp){
    if(root!=NULL){
        inorder(root->left,mp);
        mp[root->val]++;
        inorder(root->right,mp);
    }
    return;
}
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        unordered_map<int,int>mp;
        inorder(root,mp);
        int maxi = 0;
        for(auto m : mp){
            if(m.second > maxi)
            maxi = m.second;
        }
        for(auto m : mp){
            if(m.second == maxi)ans.push_back(m.first);
        }
        return ans;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/maximum-binary-tree-ii/">998.Maximum Binary Tree II</a></strong></summary>

```cpp
TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    TreeNode* res;
    if (root==NULL) {
        res = new TreeNode(val);
        return res;
    } else if (val > root->val) {
        res = new TreeNode(val);
        res->left = root;
        return res;
    } else {
        res = insertIntoMaxTree(root->right, val);
        root->right = res;
        return root;
    }
}
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/">889.Construct Binary Tree from Preorder and Postorder Traversal</a></strong></summary>

```cpp
class Solution {
public:

    int findindex(vector<int>& postorder, int element)
    {
        for(int i=0;i<postorder.size();i++)
            if(postorder[i]==element) 
                return i;
        return -1;
    }


    TreeNode* helper(vector<int>& preorder, vector<int>& postorder, int prestart, int preend, int poststart, int postend)
    {
        if(prestart>preend || poststart>postend) 
            return NULL;

        TreeNode* root = new TreeNode(preorder[prestart]);
        if(prestart==preend) 
            return root;   

        int index = findindex(postorder, preorder[prestart+1]);
        int len = index-poststart+1;
        root->left = helper(preorder, postorder, prestart+1, prestart+len, poststart, index);
        root->right = helper(preorder, postorder, prestart+len+1, preend, index+1, postend-1);
        return root;


    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        return helper(preorder, postorder, 0, n-1, 0, n-1);
    }
};
```
</details>