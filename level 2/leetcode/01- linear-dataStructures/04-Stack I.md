<details>
<summary><strong><a href = "https://leetcode.com/problems/remove-outermost-parentheses/">1021.remove outermost parentheses</a></strong></summary>

```cpp
class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int balance = 0;
        
        for (char c : s) {
            if (c == '(') {
                if (balance > 0) 
                    result += c;
                
                balance++;
            } 
            else {
                balance--;
                if (balance > 0) 
                    result += c;
            }
        }
        
        return result;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/">1047.remove all adjacent duplicates in string</a></strong></summary>

```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (!st.empty() && st.top() == c) 
                st.pop();
            
            else 
                st.push(c);
        }
        
        string result;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        
        return result;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/build-an-array-with-stack-operations/">1441.build an array with stack operations</a></strong></summary>

```cpp
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        int targetIndex = 0;

        for (int i = 1; i <= n && targetIndex < target.size(); ++i) {
            if (i == target[targetIndex]) {
                operations.push_back("Push");
                targetIndex++;
            } 
            else {
                operations.push_back("Push");
                operations.push_back("Pop");
            }
        }

        return operations;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/baseball-game/">682.baseball game</a></strong></summary>

```cpp
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        int totalScore = 0;

        for (const string& op : operations) {
            if (op == "+") {
                int top = scores.top();
                scores.pop();
                int newTop = top + scores.top();
                scores.push(top);
                scores.push(newTop);
            } 
            else if (op == "D") 
                scores.push(2 * scores.top());
            
            else if (op == "C") 
                scores.pop();
            
            
            else 
                scores.push(stoi(op));
        }

        // Calculate total score
        while (!scores.empty()) {
            totalScore += scores.top();
            scores.pop();
        }

        return totalScore;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/design-a-stack-with-increment-operation/">1381.design a stack with increment operation</a></strong></summary>

```cpp
class CustomStack {
    vector<int> stack;
    int maxSize;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (stack.size() < maxSize) 
            stack.push_back(x);
        
    }
    
    int pop() {
        if (stack.empty()) 
            return -1;
        
        else {
            int val = stack.back();
            stack.pop_back();
            return val;
        }
    }
    
    void increment(int k, int val) {
        int n = min(k, static_cast<int>(stack.size()));
        for (int i = 0; i < n; ++i) 
            stack[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/next-greater-element-i/">496.next greater element i</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> next_greater;

        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            while (!st.empty() && st.top() <= num) 
                st.pop();
            
            if (st.empty()) 
                next_greater[num] = -1;
            
            else 
                next_greater[num] = st.top();
            
            st.push(num);
        }

        vector<int> result;
        for (int num : nums1) 
            result.push_back(next_greater[num]);
        
        return result;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/crawler-log-folder/">1598.crawler log folder</a></strong></summary>

```cpp
class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> folders;
        
        for (const string& log : logs) {
            if (log == "../") {
                if (!folders.empty()) 
                    folders.pop();
                
            } else if (log == "./") 
                // Do nothing
            
            else {
                string folderName = log.substr(0, log.length() - 1);
                folders.push(folderName);
            }
        }
        
        return folders.size();
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/binary-tree-postorder-traversal/">145.binary tree postorder traversal</a></strong></summary>

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }

private:
    void postorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr)
            return; 

        postorderHelper(node->left, result);
        postorderHelper(node->right, result);
        result.push_back(node->val);
    }
};
```
</details>

<details>
<summary><strong><a href = "">144.binary tree preorder traversal</a></strong></summary>

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }

private:
    void preorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) 
            return; 
        
        result.push_back(node->val);
        preorderHelper(node->left, result);
        preorderHelper(node->right, result);
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/make-the-string-great/">1544.make the string great</a></strong></summary>

```cpp
class Solution {
public:
    string makeGood(string s) {
        stack<char> st;

        for (char c : s) {
            if (!st.empty() && abs(st.top() - c) == 32) 
                st.pop(); 
            }
            else 
                st.push(c);
            
        }

        string result;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/implement-queue-using-stacks/">232.implement queue using stacks</a></strong></summary>

```cpp
class MyQueue {
    stack <int> inputStack;
    stack <int> outputStack;

    void moveElements () {
        if (outputStack.empty()) {
            while(!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        inputStack.push(x);    
    }
    
    int pop() {
        moveElements();
        int front = outputStack.top();
        outputStack.pop();
        return front;
    }
    
    int peek() {
        moveElements();
        return outputStack.top();
    }
    
    bool empty() {
        return (inputStack.empty() && outputStack.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/implement-stack-using-queues/">225.implement stack using queues</a></strong></summary>

```cpp
class MyStack {
    queue <int> inputQueue;
    queue <int> outputQueue;

public:
    MyStack() {}
    
    void push(int x) {
        while(!inputQueue.empty()) {
            outputQueue.push(inputQueue.front());
            inputQueue.pop();
        }

        inputQueue.push(x);
        while(!outputQueue.empty()) {
            inputQueue.push(outputQueue.front());
            outputQueue.pop();
        }
    }
    
    int pop() {
        int top = inputQueue.front();
        inputQueue.pop();
        return top;
    }
    
    int top() {
        return inputQueue.front();
    }
    
    bool empty() {
        return inputQueue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/validate-stack-sequences/">946.validate stack sequences</a></strong></summary>

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack <int> temp;
        int i = 0, j = 0;
        while(i < pushed.size()) {
            temp.push(pushed[i]);
            while (!temp.empty() && j < popped.size() && popped[j] == temp.top()) {
                temp.pop();
                j++;
            }
            i++;
        }
        return temp.empty() ? true : false;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/">1190.reverse substrings between each pair of parentheses</a></strong></summary>

```cpp
class Solution {
public:
    string reverseParentheses(string s) {
        stack <char> st;
        string str = "";
        
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                st.push(s[i]);

            if(isalpha(s[i]))
                st.push(s[i]);

            if(s[i] == ')') {
                while(st.top() != '(') {
                    str += st.top();
                    st.pop();
                }

                st.pop();
                for(int i = 0; i < str.length(); i++) 
                    st.push(str[i]);

                str = "";
            }        
        }

        while(!st.empty()) {
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/">1249.minimum remove to make valid parentheses</a></strong></summary>

```cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack <int> st;
        vector <bool> is_removal(s.size(), false);
        string valid = "";

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                st.push(i);
            
            else if(s[i] == ')') {
                if(st.empty())
                    is_removal[i] = true;
                else
                    st.pop();
            }
        }

        while(!st.empty()) {
            is_removal[st.top()] = true;
            st.pop();
        }

        for(int i = 0; i < s.size(); i++) {
            if(!is_removal[i])
                valid += s[i];
        }

        return valid;
    }
};
```
</details>

<details>
<summary><strong><a href = "">901.online stock span</a></strong></summary>

```cpp
class StockSpanner {
public:
    stack <pair<int, int>> st;
    int count = 1;
    StockSpanner() {}
    
    int next(int price) {
        int ans;
        if(st.empty()) {
            st.push({price, count});
            ans = 1;
        }
        else if(!st.empty() && st.top().first > price) 
            ans = count - st.top().second;

        else if (!st.empty() && st.top().first <= price) {
            while(!st.empty() && st.top().first <= price) 
                st.pop();
            
            if(st.empty()) 
                ans = count;
            
            else 
                ans = count - st.top().second;
            
        }
        st.push({price, count});
        count++;

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
```
</details>