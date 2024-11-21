<details>
<summary><strong><a href = "https://leetcode.com/problems/throne-inheritance/description/">1600. Throne Inheritance</a></strong></summary>

```cpp
class ThroneInheritance {
public:
 unordered_map<string,vector<string>>mpp;
 unordered_map<string,int>deathn;
 string king;
 vector<string>v;
    ThroneInheritance(string kingName) {
        king=kingName;

    }
    
    void birth(string parentName, string childName) {
        mpp[parentName].push_back(childName);
    }
    
    void death(string name) {
        deathn[name]=1;
    }
    
    void dfs(vector<string> &v,string root){
        if(deathn.find(root)==deathn.end()) 
            v.push_back(root);
        
        for(auto it: mpp[root])
            dfs(v,it);
    }

    vector<string> getInheritanceOrder() {
        vector<string>v;
        dfs(v,king);
        return v;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/most-frequent-subtree-sum/description/">508. Most Frequent Subtree Sum</a></strong></summary>

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
    int count_rec(const TreeNode* const root, unordered_map<int, int>& res) {
        if(!root)
            return 0;
    
        int left = count_rec(root->left, res);
        int right = count_rec(root->right, res);
        int sum = left + right + root->val;
        res[sum]++;
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> counter;
        count_rec(root, counter);
        int max_freq = 0;
        vector<int> res;
        for(auto& [k, v] : counter) {
            if(v > max_freq) {
                max_freq = v;
                res.clear();
                res.push_back(k);
            } 
            
            else if (v == max_freq)
                res.push_back(k);
        }
        return res;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/complete-binary-tree-inserter/description/">919. Complete Binary Tree Inserter</a></strong></summary>

```cpp
class CBTInserter {
public:
    TreeNode*r;
    CBTInserter(TreeNode* root) {
        r=root;
    }
    
    int insert(int val){
        TreeNode*value = new TreeNode(val);
        queue<TreeNode*>q;
        q.push(r);
        
        while(!q.empty()){
            TreeNode*temp = q.front();
            q.pop();
            if(temp->left && temp->right){
                q.push(temp->left);
                q.push(temp->right);
                continue;
            }
        
            if(!temp->left){
                temp->left=value;
                return temp->val;
            }
        
            if(!temp->right){
                temp->right = value;
                return temp->val;
            }
        }
        return 0;
    }
    
    TreeNode* get_root() {
        return r;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/serialize-and-deserialize-bst/description/">449. Serialize and Deserialize BST</a></strong></summary>

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
class Codec {
public:

    void serialize(TreeNode* root, ostringstream &s) {
        if (root) {
            s << root->val << ' ';
            serialize(root->left, s);
            serialize(root->right, s);
        } 
        
        else 
            s << -1 << ' ';
    }

    // represent a tree in a single string.
    string serialize(TreeNode* root) {
        ostringstream s;
        serialize(root, s);
        return s.str();
    }

    TreeNode* deserialize(istringstream &s) {
        if (s.eof()) 
            return nullptr;
        
        int n = 0;
        s >> n;
        if (n == -1) 
            return nullptr;
        
        TreeNode* root = new TreeNode(n);
        root->left = deserialize(s);
        root->right = deserialize(s);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream s(data);
        return deserialize(s);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/">1339. Maximum Product of Splitted Binary Tree</a></strong></summary>

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
#define mod 1000000007
    void Inorder1(TreeNode*tmp,long long int &total){
        if(tmp==NULL)
            return ;
        
        if(tmp->left)
            Inorder1(tmp->left,total);
        
        total+=tmp->val;
        if(tmp->right)
            Inorder1(tmp->right,total);
    }

    long long int Inorder(TreeNode*root,long long int total,long long int  sm,long long int&res){
        if(root==NULL)
            return 0;
        
        int lft=root->val+Inorder(root->left,total,sm,res);
        int rgt=root->val+Inorder(root->right,total,sm,res);
        sm=sm+lft+rgt-root->val;
        long long int sm2=total-sm;
        long long int val=(sm*sm2);
        res=max(res,val);
        return lft+rgt-root->val;
    }

    int maxProduct(TreeNode* root) {
        long long int total=0;
        TreeNode*tmp=root;
        Inorder1(tmp,total);
    
        long long int res=-1;
        Inorder(root,total,0,res);
    
        return res%mod;
        
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/delete-node-in-a-bst/description/">450. Delete Node in a BST</a></strong></summary>

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
TreeNode* maxvalue(TreeNode* root){
    if(!root) 
        return NULL;
    
    while(root->right!=NULL)
       root=root->right;
    
    return root;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val==key){
            if(root->left==NULL && root->right==NULL){  //leaf
                delete root;
                return NULL;
            }
            
            if(root->left!=NULL && root->right==NULL){  //lsubtree
                TreeNode* leftchild=root->left;
                delete root;
                return leftchild;
            }
            
            if(root->left==NULL && root->right!=NULL){  //rsubtree
                TreeNode* rightchild=root->right;
                delete root;
                return rightchild;
            }
            
            if(root->left!=NULL && root->right!=NULL){  //both
                TreeNode* maxi=maxvalue(root->left);
                root->val=maxi->val;
                root->left=deleteNode(root->left,maxi->val);
                return root;
            }
        }

        else if(root->val>key)
            root->left=deleteNode(root->left,key);
        
        else
           root->right=deleteNode(root->right,key);
        
        return root;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/print-binary-tree/description/">655. Print Binary Tree</a></strong></summary>

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
    int treeHeight;

    void fillValues(TreeNode* node, vector<vector<string>>& matrix, int row, int col) {
        if (!node) 
            return;
        
        matrix[row][col] = to_string(node->val);
        int leftCol = col - pow(2, treeHeight - row - 1);
        int rightCol = col + pow(2, treeHeight - row - 1);
        fillValues(node->left, matrix, row + 1, leftCol);
        fillValues(node->right, matrix, row + 1, rightCol);
    }

    int calculateHeight(TreeNode* node) {
        if (!node) 
            return 0;
        
        return 1 + max(calculateHeight(node->left), calculateHeight(node->right));
    }

public:
    vector<vector<string>> printTree(TreeNode* root) {
        treeHeight = calculateHeight(root) - 1;
        int width = pow(2, treeHeight + 1) - 1;

        vector<vector<string>> result(treeHeight + 1, vector<string>(width, ""));
        int startRow = 0;
        int startCol = (width - 1) / 2;

        fillValues(root, result, startRow, startCol);
        return result;
    }
};
```
</details>