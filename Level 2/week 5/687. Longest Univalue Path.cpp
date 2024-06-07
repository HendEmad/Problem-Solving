class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        max_length = 0; // Initialize max_length
        dfs(root);
        return max_length;
    }

private:
    int max_length; // Global variable to store the maximum length of the same value path

    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0}; // Base case

        auto [left_length, left_value] = dfs(node->left);
        auto [right_length, right_value] = dfs(node->right);

        int length = 0;

        // Check if the current node value matches the values of its left and right children
        if (node->left && node->left->val == node->val) {
            left_length++;
        } else {
            left_length = 0;
        }

        if (node->right && node->right->val == node->val) {
            right_length++;
        } else {
            right_length = 0;
        }

        // Update the length of the longest path for the current node
        length = left_length + right_length;

        // Update the max_length if necessary
        max_length = max(max_length, length);

        // Return the pair (length, value) to the parent call
        return {max(left_length, right_length), node->val};
    }
};