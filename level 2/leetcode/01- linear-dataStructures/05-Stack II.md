<details>
<summary><strong><a href = "https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/">1209.remove all adjacent duplicates in string ii</a></strong></summary>

```cpp
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        st.push({'A',1});

        for(auto i:s){
            i==st.top().first?st.push({i,st.top().second+1}):st.push({i,1});
            if(st.top().second==k){
                int temp=k;
                while(temp--)
                    st.pop();
            }
        }

        string str;
        
        while(st.top().first!='A'){
            str.push_back(st.top().first);
            st.pop();
        }
        
        reverse(str.begin(),str.end());
        
        return str;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/">1003.check if word is valid after substitutions</a></strong></summary>

```cpp
class Solution {
public:
    bool isValid(string s) {
        if(s[0]!='a')
            return false;
        
        stack<char> st;
        
        for(char ch:s){
            if(ch=='a')
                st.push(ch);
            else if(ch=='b'){
                if(!st.empty()&&st.top()=='a')
                    st.push(ch);
                else
                    return false;
            } else{
                if(!st.empty()&&st.top()=='b'){
                    st.pop();
                        if(!st.empty()&&st.top()=='a')
                            st.pop();
                        else 
                            return false;
                    }
                    else
                        return false;
            }
        }
        
        return st.empty();
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/flatten-nested-list-iterator/">341.flatten nested list iterator</a></strong></summary>

```cpp
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> ans;
    int k=0;

    void solve(vector<NestedInteger> &n){
        for(int i=0;i<n.size();i++){
            if(n[i].isInteger())
                ans.push_back(n[i].getInteger());
            else 
               solve(n[i].getList()); 
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        solve(nestedList);
    }

    
    int next() {
        return ans[k++];
    }
    
    bool hasNext() {
        if(k<ans.size()) 
            return true;
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/exclusive-time-of-functions/">636.exclusive time of functions</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> execution_times(n, 0);
        stack<int> call_stack;
        int prev_start_time = 0;

        for(const string& log: logs) {
            stringstream ss(log);
            string token;
            vector<string> tokens;

            while(getline(ss, token, ':')) {
                tokens.push_back(token);
            }

            int func_id = stoi(tokens[0]);
            string call_type = tokens[1];
            int timestamp = stoi(tokens[2]);

            if(call_type == "start") {
                if(!call_stack.empty()) {
                    execution_times[call_stack.top()] += timestamp - prev_start_time;
                }
                call_stack.push(func_id);
                prev_start_time = timestamp;
            }else {
                execution_times[call_stack.top()] += timestamp - prev_start_time + 1;
                prev_start_time = timestamp + 1;
                call_stack.pop();
            }
        }
        return execution_times;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/html-entity-parser/">1410.html entity parser</a></strong></summary>

```cpp
class Solution {
public:
    string entityParser(string text) {
        int n = text.size();
        string ans = "";
        int i = 0;

        while (i < n) {
            if (i+6 < n && text.substr(i, 7) == "&frasl;") {
                ans += "/";
                i += 7;
            }
            else if(i+5 < n && (text.substr(i, 6) == "&quot;" || text.substr(i, 6) == "&apos;")) {
                if (text.substr(i, 6) == "&quot;")
                    ans += '"';
                else
                    ans += "'";
                i += 6;
            }
            else if(i+4 < n && text.substr(i, 5) == "&amp;") {
                ans += "&";
                i += 5;
            }
            else if(i+3 < n && (text.substr(i, 4) == "&gt;" || text.substr(i, 4) == "&lt;")) {
                if (text.substr(i, 4) == "&gt;")
                    ans += ">";
                else
                    ans += "<";
                i += 4;
            }
            else {
                ans += text[i];
                i++;
            }
        }
        return ans;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/decoded-string-at-index/">880.decoded string at index</a></strong></summary>

```cpp
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long sz = 0;
        // first calculate total decoded length size
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z') sz++;
            else sz *= (long long)(s[i] - '0');
        }
        // after that size if "string.length"x ,then do k %= (string.length());
        // where , 2 <= x <= 9
        for(int i = s.size()-1 ; i >= 0 ; i--){
            if(s[i] >= 'a' && s[i] <= 'z'){
                if(k == sz || k == 0) return string(1,s[i]);
                sz--;
            }
            else{
                int n = (s[i] - '0');
                sz /= n;
                k %= sz;
            }
        }

        return "";
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/sum-of-subarray-minimums/">907.sum of subarray minimums</a></strong></summary>

```cpp
class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long result = 0;
        vector<int> prev_smaller(n, -1); // Store the index of previous smaller element
        vector<int> next_smaller(n, n);  // Store the index of next smaller element

        // Find the previous smaller element
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            prev_smaller[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Clear the stack for next pass
        while (!s.empty()) {
            s.pop();
        }

        // Find the next smaller element
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            next_smaller[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        for (int i = 0; i < n; i++) {
            long long count = (i - prev_smaller[i]) * (next_smaller[i] - i) % MOD;
            result = (result + count * arr[i]) % MOD;
        }

        return result;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/132-pattern/">456.132 pattern</a></strong></summary>

```cpp
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> candidate;
        int third = INT_MIN; 

        for (int i = n - 1; i >= 0; i--) {
            // If we find a number smaller than the potential candidate for "3", it means we've found a valid 132 pattern
            if (nums[i] < third) {
                return true;
            }
            while (!candidate.empty() && nums[i] > candidate.top()) {
                third = candidate.top();
                candidate.pop();
            }
            candidate.push(nums[i]);
        }

        return false;   
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/">331.verify preorder sequence in binary search tree</a></strong></summary>

```cpp
// Time complexity = O(n), space complexity = O(1)
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.length();
        if(n == 0)
            return true;

        if(preorder[0]=='#' && n == 1)
            return true;
        if(preorder[0]=='#' && n > 1)
            return false;
        
        int cnt = 1;
        bool next = true;

        for(int i = 0; i<n; i++){
            if(preorder[i] == ','){
                next = true;
                continue;
            }

            if(cnt-1 < 0)
                return false;

            if(preorder[i] == '#'){
                cnt--;
            }
            else{
                if(next)
                    cnt++;
                next = false;
            }

        }

        return (cnt == 0);
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/">1541.minimum insertions to balance a parentheses string</a></strong></summary>

```cpp
class Solution {
public:
    int minInsertions(string s) {
        stack<char>st;
        int ans=0;
        int i=0;

        while(i<s.length()){
            if(s[i]=='('){
                st.push(s[i]);
                i++;
            }
            else if(s[i]==')'){
                if(st.empty()){
                    if((i+1)<s.length()){
                        if(s[i+1]!=')'){
                            ans+=2;
                            i++;
                        }
                        else{
                            ans++;
                            i+=2;
                        }
                    }
                    else{
                        ans+=2;
                        i++;
                    }
                }
                else{
                    st.pop();
                    if((i+1)<s.length()){
                        if(s[i+1]!=')'){
                            ans+=1;
                            i++;
                        }
                        else
                            i+=2;
                    }
                    else{
                        ans++;
                        i++;
                    }
                }
            }
        }

        while(!st.empty()){
            ans+=2;
            st.pop();
        }
        
        return ans;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/asteroid-collision/">735.asteroid collision</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> myStack;
        for(int i=0;i<asteroids.size();i++){
            if(i==0 || myStack.empty() || asteroids[i]>0){
                myStack.push(asteroids[i]);
                continue;
            }

            //IF negative asteroid
            int flag=0;
            while(!myStack.empty() && myStack.top()>0){
                if(abs(asteroids[i]) == abs(myStack.top())){
                    myStack.pop();
                    flag=1;
                    break;
                }else if(abs(asteroids[i]) > abs(myStack.top())){
                    myStack.pop();
                }else{
                    flag=1;
                    break;  //If negative asteroid is smaller
                }
            }
            if(flag==0){
                myStack.push(asteroids[i]);
            }
        }

        vector<int> ans(myStack.size(),0);
        for(int i=myStack.size()-1;i>=0;i--){
            ans[i]=myStack.top();
            myStack.pop();

        }
        return ans;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/mini-parser/">385.mini parser</a></strong></summary>

```cpp
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s[0] != '[') return NestedInteger(stoi(s)); // if string contains single number ex: "123".
    
        vector<NestedInteger> v; // using vector to simulate stack
        string num = ""; // num will store the number, number can be negative or positive.
    
        for(auto c: s){
            if(c == '['){
                v.push_back(NestedInteger());
            }
            else if(c == ']' or c == ','){
                if(num != ""){
                    v.back().add(NestedInteger(stoi(num)));
                    num = "";
                }
            
                if(c == ']' and v.size() >= 2){
                    NestedInteger ni = v.back();
                    v.pop_back();
                    v.back().add(ni);
                }
            }
            else num.push_back(c); // if c is a digit just add to num.
        }
    
        return v.back();
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/longest-well-performing-interval/">1124.longest well performing interval</a></strong></summary>

```cpp
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int sz=hours.size(),len=0;
        for(int i=0;i<sz;i++){
           int t=0,nt=0;
           for(int j=i;j<sz;j++){
                if(hours[j]>8)
                    t++;
                else
                    nt++;  
                if(nt<t)
                    len=max(len,j-i+1);
            }
        }
            return len;
    }
};
```
</details>