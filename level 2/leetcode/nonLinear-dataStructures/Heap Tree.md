<details>
<summary><strong><a href = "https://leetcode.com/problems/super-ugly-number/">super ugly number</a></strong></summary>

```cpp
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long, vector<long>, greater<long>> pq;  // min_heap

        pq.push(1);
        long current_ugly = 0;

        for(int i = 0; i < n; i++) {
            current_ugly = pq.top();
            pq.pop();

            for(int prime : primes) {  // 2, 3, 5
                if(current_ugly <= INT_MAX / prime) // current_ugly = 12, prime = 2
                    pq.push(prime * current_ugly);  // [15, 16, 18, 20, 24, 25, 27]
                
                if(current_ugly % prime == 0)
                    break;
            }
        }
        return (int)current_ugly;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/kth-largest-element-in-a-stream/">kth largest element in a stream</a></strong></summary>

```cpp
class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    KthLargest(int k, vector<int>& nums) {
        this -> k = k;
        for(int &num : nums) 
            add(num);
    }
    
    int add(int val) {
        if(min_heap.size() < k)
            min_heap.push(val);
        else if (val > min_heap.top()) {
            min_heap.pop();
            min_heap.push(val);
        }
        return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/seat-reservation-manager/">seat reservation manager</a></strong></summary>

```cpp
class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    SeatManager(int n) {
        for(int i = 1; i <= n; i++)
            min_heap.push(i);
    }
    
    int reserve() {
        int seat = min_heap.top();
        min_heap.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        min_heap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/maximum-score-from-removing-stones/">maximum score from removing stones</a></strong></summary>

```cpp
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> max_heap;
        max_heap.push(a);
        max_heap.push(b);
        max_heap.push(c);

        int res = 0, maxi1, maxi2;
        while(true) {
            maxi1 = max_heap.top();
            max_heap.pop();
            maxi2 = max_heap.top();
            max_heap.pop();

            if(maxi1 == 0 or maxi2 == 0)
                break;

            res++;
            max_heap.push(maxi1 - 1);
            max_heap.push(maxi2 - 1);
        }
        return res;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/maximum-average-pass-ratio/">maximum average pass ratio</a></strong></summary>

```cpp
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> max_heap;
        double avg = 0, res = 0;

        // calculating the potential increase if we add one extra student, find
        // the max among all pairs of classes
        for (int i = 0; i < classes.size(); i++) {
            double diff =
                ((double)(classes[i][0] + 1) / (double)(classes[i][1] + 1)) -
                (double)classes[i][0] / (double)classes[i][1];
            max_heap.push({diff, i});
        }

        // adding all extra students and re-calculate the potential difference,
        // find max between
        while (extraStudents--) {
            int i = max_heap.top().second;
            max_heap.pop();
            classes[i][0]++;
            classes[i][1]++;
            double diff =
                ((double)(classes[i][0] + 1) / (double)(classes[i][1] + 1)) -
                (double)classes[i][0] / (double)classes[i][1];
            max_heap.push({diff, i});
        }

        for (int i = 0; i < classes.size(); i++) {
            avg = (double)classes[i][0] / (double)classes[i][1];
            res += avg;
        }
        return res / classes.size();
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/top-k-frequent-words/">top k frequent words</a></strong></summary>

```cpp

```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/hand-of-straights/">hand of straights</a></strong></summary>

```cpp

```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/my-calendar-ii/">my calendar ii</a></strong></summary>

```cpp

```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/exam-room/">exam room</a></strong></summary>

```cpp

```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/">	alert using same key card three or more times in a one hour period</a></strong></summary>

```cpp

```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/">	number of distinct substrings in a string</a></strong></summary>

```cpp

```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/single-threaded-cpu/">single threaded cpu</a></strong></summary>

```cpp

```
</details>