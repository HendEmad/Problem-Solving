<details>
<summary><strong><a href = "https://leetcode.com/problems/k-th-symbol-in-grammar/">779.k-th symbol in grammar</a></strong></summary>

```cpp
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0; // Base case
        
        // Calculate the position of k in the (n-1)th row
        int mid = pow(2, n - 1) / 2;
        
        // If k is in the first half of the row, the result is the same as in the (n-1)th row
        if (k <= mid) {
            return kthGrammar(n - 1, k);
        } else {
            // If k is in the second half of the row, the result is the complement of the symbol in the (n-1)th row
            return 1 - kthGrammar(n - 1, k - mid);
        }
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/longest-univalue-path/">687.longest univalue path</a></strong></summary>

```cpp
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
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/design-twitter/">355.design twitter</a></strong></summary>

```cpp
class Twitter {
public:
    vector<pair<int, int>> cake; // userid, tweet id
    unordered_map<int, unordered_set<int>> f; 
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        cake.push_back(make_pair(userId, tweetId));
        f[userId].insert(userId);        
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> toret;
        for(int i=cake.size()-1;i>=0;i--){
            if(toret.size()==10){
                return toret;
            }
            if(f[userId].find(cake[i].first)!=f[userId].end()){
                toret.push_back(cake[i].second);
            }

        }return toret;
        
    }
    
    void follow(int followerId, int followeeId) {
        f[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        f[followerId].erase(followeeId);
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/4sum/">18.4sum</a></strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int >>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;

            for(int j=i+1;j<n;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;

                int k=j+1;
                int l=n-1;

                while(k<l)
                {
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];

                    if(sum==target)
                    {
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]){k++;}
                        while(k<l && nums[l]==nums[l+1]){l--;}
                    }
                    else if(sum<target)
                    {
                        k++;
                    }
                    else {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/trim-a-binary-search-tree/">669.trim a binary search tree</a></strong></summary>

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
    void trim(TreeNode* root, int lo, int hi){
        if(root==NULL) return ;
        while(root->left != NULL){
            if(root->left->val < lo){
                root->left=root->left->right;
            }
            else if(root->left->val > hi){
                root->left=root->left->left;
            }
            else break;
        }
        while(root->right != NULL){
            if(root->right->val > hi){
                root->right=root->right->left;
            } 
            else if(root->right->val < lo){
                root->right=root->right->right;
            }
            else break;
        }
        trim(root->left,lo,hi);
        trim(root->right,lo,hi);
    }
    TreeNode* trimBST(TreeNode* root, int lo, int hi) {
        TreeNode* dummy=new TreeNode(INT_MAX);
        dummy->left=root;
        trim(dummy,lo,hi);
        return dummy->left;
        
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/get-equal-substrings-within-budget/">1208.get equal substrings within budget</a></strong></summary>

```cpp
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int start = 0, end = 0, totalCost = 0, maxLength = 0;
        
        while (end < n) {
            totalCost += abs(s[end] - t[end]);
            while (totalCost > maxCost) {
                totalCost -= abs(s[start] - t[start]);
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
            end++;
        }
        
        return maxLength;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/basic-calculator-ii/">227.basic calculator ii</a></strong></summary>

```cpp
class Solution {
public:
    int calculate(string s) {
        stack<int> operands;
        int num = 0;
        char sign = '+';

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if ((!isdigit(c) && c != ' ') || i == s.length() - 1) {
                if (sign == '+') {
                    operands.push(num);
                } else if (sign == '-') {
                    operands.push(-num);
                } else if (sign == '*') {
                    int prev = operands.top();
                    operands.pop();
                    operands.push(prev * num);
                } else if (sign == '/') {
                    int prev = operands.top();
                    operands.pop();
                    operands.push(prev / num);
                }
                sign = c;
                num = 0;
            }
        }
        
        int result = 0;
        while (!operands.empty()) {
            result += operands.top();
            operands.pop();
        }
        
        return result;
    }
};
```
</details>