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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }

private:
    void postorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return; // Base case: if node is null, return
        
        // Recursively traverse the left subtree
        postorderHelper(node->left, result);
        
        // Recursively traverse the right subtree
        postorderHelper(node->right, result);
        
        // Visit the current node
        result.push_back(node->val);
    }
};