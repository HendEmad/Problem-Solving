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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }

private:
    void preorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return; // Base case: if node is null, return
        
        // Visit the current node
        result.push_back(node->val);
        
        // Recursively traverse the left subtree
        preorderHelper(node->left, result);
        
        // Recursively traverse the right subtree
        preorderHelper(node->right, result);
    }
};