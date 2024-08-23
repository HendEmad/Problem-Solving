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
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        for(int i = 0; i < words.size(); i++) {
            map[words[i]]++;
        }

        auto cmp = [] (const pair<int, string>& a, const pair<int, string>&b) {
            if(a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);

        for(const auto& [word, freq] : map) {
            pq.push({freq, word});  
        }

        vector <string> res;
        for(int i = 0; i < k && !pq.empty(); i++) {
            res.emplace_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/hand-of-straights/">hand of straights</a></strong></summary>

```cpp
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int handSize = hand.size();

        if (handSize % groupSize != 0) {
            return false;
        }

        map<int, int> cardCount;
        for (int i = 0; i < handSize; i++) {
            cardCount[hand[i]]++;
        }

        while (!cardCount.empty()) {
            int currentCard = cardCount.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                if (cardCount[currentCard + i] == 0) {
                    return false;
                }
                cardCount[currentCard + i]--;
                if (cardCount[currentCard + i] < 1) {
                    cardCount.erase(currentCard + i);
                }
            }
        }
        return true;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/my-calendar-ii/">my calendar ii</a></strong></summary>

```cpp
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    map<int, int> calender;
    bool book(int start, int end) {
        calender[start]++;
        calender[end]--;
        int sum = 0;

        for(auto &c : calender) {
            sum += c.second;
            if(sum >= 3) {
                calender[start]--;
                calender[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/exam-room/">exam room</a></strong></summary>

```cpp
class ExamRoom {
private:
    int n;
    set<int> seats;

public:
    ExamRoom(int n) : n(n){}
    
    int seat() {
        int student = 0;

        if(!seats.empty()) {
            int maxDist = *seats.begin();

            auto prev = seats.begin();
            for(auto it = next(seats.begin()); it != seats.end(); it++) {
                int dist = (*it - *prev) / 2;
                if(dist > maxDist) {
                    maxDist = dist;
                    student = *prev + dist;
                }
                prev = it;
            }

            if(n - 1 - *seats.rbegin() > maxDist) {
                student = n - 1;
            }
        }

        seats.insert(student);
        return student;
    }
    
    void leave(int p) {
        seats.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/">	alert using same key card three or more times in a one hour period</a></strong></summary>

```cpp
class Solution {
public:
    int timeToMinutes(const string& time) {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        return hours * 60 + minutes;
    }

    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, vector<int>> nameToTimes;

        for (int i = 0; i < keyName.size(); ++i) {
            nameToTimes[keyName[i]].push_back(timeToMinutes(keyTime[i]));
        }

        set<string> alertedNames;

        for (auto& entry : nameToTimes) {
            string name = entry.first;
            vector<int> times = entry.second;

            sort(times.begin(), times.end());

            if(times.size() < 3) continue;
            
            for (int i = 0; i < times.size() - 2; ++i) {
                if (times[i + 2] - times[i] <= 60) {
                    alertedNames.insert(name);
                    break;  
                }
            }
        }

        return vector<string>(alertedNames.begin(), alertedNames.end());
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/single-threaded-cpu/">single threaded cpu</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<int> enqueueTime(n), processingTime(n), index(n);
        for(int i = 0; i < n; i++) {
            enqueueTime[i] = tasks[i][0];
            processingTime[i] = tasks[i][1];
            index[i] = i;
        }

        vector<int> sortedIndices(n);
        iota(sortedIndices.begin(), sortedIndices.end(), 0);
        sort(sortedIndices.begin(), sortedIndices.end(), [&enqueueTime](int a, int b) {
            return enqueueTime[a] < enqueueTime[b];
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> availableTasks;

        vector<int> result;
        long long currentTime = 0;
        int idx = 0;
        int taskCount = 0;

        while(taskCount < n) {
            while (idx < n && enqueueTime[sortedIndices[idx]] <= currentTime) {
                availableTasks.push({processingTime[sortedIndices[idx]], sortedIndices[idx]});
                ++idx;
            }

            if (availableTasks.empty()) {
                if (idx < n) {
                    currentTime = enqueueTime[sortedIndices[idx]];
                }
                continue;
            }

            auto [procTime, taskIndex] = availableTasks.top();
            availableTasks.pop();
            
            result.push_back(taskIndex);
            currentTime += procTime;
            ++taskCount;
        }
        return result;
    }
};
```
</details>