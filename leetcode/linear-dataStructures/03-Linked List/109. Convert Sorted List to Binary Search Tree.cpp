/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* BST(vector<int>& v){
        if(v.size()==0) 
            return NULL;
        if(v.size()==1) 
            return new TreeNode(v[0]);

        int mid = v.size()/2;
        TreeNode* root= new TreeNode(v[mid]);

        vector<int> leftTree(v.begin(),v.begin()+mid);
        vector<int> rightTree(v.begin()+mid+1,v.end());

        root->left = BST(leftTree);
        root->right = BST(rightTree);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp=head;
        vector<int> v;

        // Converting LinkedList into array
        while(temp){
            v.emplace_back(temp->val);
            temp=temp->next;
        }

        if(v.size()==0) 
            return NULL;
        if(v.size()==1) 
            return new TreeNode(v[0]);

        return BST(v);
    }
};
