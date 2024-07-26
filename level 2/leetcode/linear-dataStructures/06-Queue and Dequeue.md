<details>
<summary><strong><a href = "https://leetcode.com/problems/number-of-recent-calls/">933.number of recent calls</a></strong></summary>

```cpp
class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {}
    
    int ping(int t) {
        int range = t - 3000;
        q.push(t);
        while(!q.empty() && q.front() < range) 
            q.pop();
        
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/design-circular-deque/">641.design circular deque</a></strong></summary>

```cpp
class MyCircularDeque {
public:
    int n;
    class DLL {
    public:
        int val;
        DLL* next;
        DLL* prev;
        DLL (int n) {
            val = n;
        }
    };

    DLL* head = new DLL(-1);
    DLL* tail = new DLL(-1);
    DLL* lastAdded = tail;
    int curSize = 0;

    MyCircularDeque(int k) {
        n = k;
        head -> next = tail;
        tail -> prev = head;
    }
    
    bool insertFront(int value) {
        if (curSize == n)
            return false;

        curSize++;
        DLL* temp = new DLL(value);
        temp -> next = head -> next;
        head -> next -> prev = temp;
        head -> next = temp;
        temp -> prev = head;
        return true;
    }


    
    bool insertLast(int value) {
        if (curSize == n)
            return false;
        curSize++;
        DLL* temp = new DLL(value);
        temp -> next = tail;
        tail -> prev -> next = temp;
        tail -> prev = temp;
        temp -> prev = tail -> prev;
        return true;
    }
    
    bool deleteFront() {
        if (curSize == 0)
            return false;
        DLL* temp = head -> next;
        head -> next -> prev = head;
        head -> next = temp -> next;
        temp -> next = temp -> prev = NULL;
        curSize--;
        return true;
    }
    
    bool deleteLast() {
        if (curSize == 0)
            return false;
        DLL* temp = tail -> prev;
        tail -> prev = temp -> prev;
        temp -> prev -> next = tail;
        temp -> prev = temp -> next = NULL;
        curSize--;
        return true;
    }
    
    int getFront() {
        if (head -> next -> val == -1)
            return -1;
        return head -> next -> val;
    }
    
    int getRear() {
        if (tail -> prev -> val == -1)
            return -1;
        return tail -> prev -> val;
    }
    
    bool isEmpty() {
        return (curSize == 0);
    }
    
    bool isFull() {
        return (curSize == n);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/design-circular-queue/">622.design circular queue</a></strong></summary>

```cpp
class MyCircularQueue {
int rear, front, length, *arr, size;
public:
    MyCircularQueue(int k) : size(k), rear(k - 1), front(0), length(0), arr(new int[k]) {}

    
    bool enQueue(int value) {
        if(isFull()) 
            return false;
        rear = (rear + 1) % size;
        arr[rear] = value;
        length++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        front = (front + 1) % size;
        --length;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()) 
            return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return length == 0;
    }
    
    bool isFull() {
        return length == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/jump-game-vi/">1696.jump game vi</a></strong></summary>

```cpp
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        deque<int> dq;

        dp[0] = nums[0];
        dq.push_back(0);

        for (int i = 1; i < n; i++) {
            while (!dq.empty() && dq.front() < i - k) {
                dq.pop_front();
            }

            dp[i] = nums[i] + dp[dq.front()];

            while (!dq.empty() && dp[i] >= dp[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

    return dp[n - 1];
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/score-of-parentheses/">856.score of parentheses</a></strong></summary>

```cpp
class Solution {
public:
    int scoreOfParentheses(string s) {
    stack<int> st;
    int currentScore = 0;

    for (char c : s) {
        if (c == '(') {
            st.push(currentScore);
            currentScore = 0;
        } else {
            currentScore = st.top() + max(2 * currentScore, 1);
            st.pop();
        }
    }

    return currentScore;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/design-front-middle-back-queue/">1670.design front middle back queue</a></strong></summary>

```cpp
class FrontMiddleBackQueue {
    deque<int>dq;
    stack<int>s;
public:
    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {
        dq.push_front(val);
    }
    
    void pushMiddle(int val) {
        int n=dq.size()/2;
        for(int i=0;i<n;i++)
        {
            s.push(dq.front());
            dq.pop_front();
        }
        dq.push_front(val);
        while(!s.empty())
        {
            dq.push_front(s.top());
            s.pop();
        }
    }
    
    void pushBack(int val) {
        dq.push_back(val);
    }
    
    int popFront() {
        int ans=-1;
        if(!dq.empty()){
            ans=dq.front();
            dq.pop_front();
        }
        return ans;
    }
    
    int popMiddle() {
        if(dq.empty())
        return -1;
        int n=dq.size();
        if(n%2==0)
        n=(dq.size()/2)-1;
        else
        n=dq.size()/2;
        for(int i=0;i<n;i++)
        {
            s.push(dq.front());
            dq.pop_front();
        }
        int ans=dq.front();
        dq.pop_front();
        while(!s.empty())
        {
            dq.push_front(s.top());
            s.pop();
        }
        return ans;
    }
    
    int popBack() {
        int ans=-1;
        if(!dq.empty())
        {
            ans=dq.back();
            dq.pop_back();
        }
        return ans;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/max-consecutive-ones-iii/">1004.max consecutive ones iii</a></strong></summary>

```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int zeroCount = 0;
        int maxLength = 0;

        for (right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                zeroCount++;
            }

            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/grumpy-bookstore-owner/">1052.grumpy bookstore owner</a></strong></summary>

```cpp
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int baseSatisfaction = 0;
        int maxExtraSatisfaction = 0;
        int currentExtraSatisfaction = 0;

        // Calculate base satisfaction (customers satisfied when owner is not grumpy)
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                baseSatisfaction += customers[i];
            }
        }

        // Sliding window to find the maximum extra satisfaction
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 1) {
                currentExtraSatisfaction += customers[i];
            }
            if (i >= minutes && grumpy[i - minutes] == 1) {
                currentExtraSatisfaction -= customers[i - minutes];
            }
            maxExtraSatisfaction = max(maxExtraSatisfaction, currentExtraSatisfaction);
        }

        return baseSatisfaction + maxExtraSatisfaction;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/">1456.	maximum number of vowels in a substring of given length</a></strong></summary>

```cpp
class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int maxVowelCount = 0, currentVowelCount = 0;
    
        // Count vowels in the first window
        for (int i = 0; i < k; ++i) {
            if (vowels.count(s[i])) {
                currentVowelCount++;
            }
        }
        maxVowelCount = currentVowelCount;
    
        // Sliding window
        for (int i = k; i < s.length(); ++i) {
            if (vowels.count(s[i])) {
                currentVowelCount++;
            }
            if (vowels.count(s[i - k])) {
                currentVowelCount--;
            }
            maxVowelCount = max(maxVowelCount, currentVowelCount);
        }
    
        return maxVowelCount;
    }   
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/moving-stones-until-consecutive-ii/">1040.moving stones until consecutive ii</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
    
        // Calculate max moves
        int max_moves = max(stones[n-1] - stones[1] - (n - 2), stones[n-2] - stones[0] - (n - 2));
    
        // Calculate min moves
        int min_moves = n;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && stones[j] <= stones[i] + n - 1) {
                ++j;
            }
            int already_in_window = j - i;
            if (already_in_window == n - 1 && stones[j - 1] - stones[i] == n - 2) {
                // Special case: one stone out of place, edge case
                min_moves = min(min_moves, 2);
            } else {
                min_moves = min(min_moves, n - already_in_window);
            }
        }
    
        return {min_moves, max_moves};
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/">1438.longest continuous subarray with absolute diff less than or equal to limit</a></strong></summary>

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int left = 0, maxLength = 0;
    
        for (int right = 0; right < nums.size(); ++right) {
            // Maintain maxDeque
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);
        
            // Maintain minDeque
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);
        
            // Check if the current window is valid
            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                left++;
                if (maxDeque.front() < left) maxDeque.pop_front();
                if (minDeque.front() < left) minDeque.pop_front();
            }
        
            // Update the maximum length of valid subarray
            maxLength = max(maxLength, right - left + 1);
        }
    
        return maxLength;
    }
};
```
</details>