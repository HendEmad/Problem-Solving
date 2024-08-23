<details>
<summary><strong><a href = "https://leetcode.com/problems/prison-cells-after-n-days/">prison cells after n days</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> next(cells.size(), 0);
        n = (n - 1) % 14 + 1;

        for (int day = 0; day < n; ++day) {
            for (int i = 1; i < cells.size() - 1; ++i) {
                if (cells[i - 1] == cells[i + 1]) 
                    next[i] = 1;
                else 
                    next[i] = 0;
            }

            cells = next;
            fill(next.begin(), next.end(), 0);
        }
        return cells;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/maximum-distance-in-arrays/">maximum distance in arrays</a></strong></summary>

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>> pq1;
        priority_queue<pair<int, int>> pq2;
        int n = arr.size();
        
        for(int i = 0; i<n; i++){
            pq1.push({arr[i].back(), i});
            pq2.push({arr[i].front(), i});
            if(i >= 2) 
                pq1.pop(), pq2.pop();
        }

        int x1 = pq1.top().first; 
        pq1.pop();
        
        int x2 = pq1.top().first;
        int z1 = pq1.top().second;
        
        int y1 = pq2.top().first; 
        pq2.pop();
        
        int y2 = pq2.top().first;
        int z2 = pq2.top().second;
        
        if(z1 != z2) 
            return abs(x2-y2);
        
        return max(abs(x1 - y2), abs(x2 - y1));
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/count-nice-pairs-in-an-array/">count nice pairs in an array</a></strong></summary>

```cpp
class Solution {
public:
    int rev(int num){
        int reversed = 0;
        while (num != 0) {
            int digit = num % 10;
            num /= 10;
            reversed = reversed * 10 + digit;
        }
        return reversed;
    }

    int MOD = 1e9+7;
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int>mp;
        
        for(int i = 0 ; i < n ; i++)
            nums[i] = nums[i]-rev(nums[i]);

        for(int i = 0 ; i < n ; i++){ 
            count = (count + mp[nums[i]]) %MOD;
            mp[nums[i]]++;
        }
        
        return count;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/">number of ways where square of number is equal to product of two numbers</a></strong></summary>

```cpp
class Solution 
{
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) 
    {
        map<long long,int> m1, m2;
        for(auto n: nums1) 
            m1[(long long)n * n]++;

        for(auto n: nums2) 
            m2[(long long)n * n]++;
        
        int ans = 0;
        for(int x = 0; x < nums2.size(); x++)
            for(int y = x+1; y < nums2.size(); y++)
                ans += m1[(long long)nums2[x] * nums2[y]];

        for(int x = 0; x < nums1.size(); x++)
            for(int y = x+1; y < nums1.size(); y++)
                ans += m2[(long long)nums1[x] * nums1[y]];
        
        return ans;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/array-of-doubled-pairs/">array of doubled pairs</a></strong></summary>

```cpp
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        map<int, int> pos, neg;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) 
                pos[arr[i]]++;
            else 
                neg[arr[i]]++;
        }

        for (auto it : pos) {
            if (it.first == 0 && it.second % 2 != 0) 
                return false;

            if (it.second == 0) 
                continue;
    
            if (it.first == 0) {
                pos[it.first] = 0;
                continue;
            }

            if (it.first > 0) {
                if (pos.find(2 * it.first) == pos.end() ||
                    pos[2 * it.first] < pos[it.first]) {
                    return false;
                }
                pos[2 * it.first] -= pos[it.first];
                pos[it.first] = 0;
            }
        }

        for (auto it : neg) {
            if (it.first % 2 != 0) 
                return false;
            
            if (neg.find(it.first / 2) == neg.end() ||
                neg[it.first / 2] < neg[it.first]) {
                return false;
            }

            neg[it.first / 2] -= neg[it.first];
            neg[it.first] = 0;
            if (neg[it.first / 2] == 0) 
                neg.erase(it.first / 2);
            
            if (neg[it.first] == 0) 
                neg.erase(it.first);
        }
        
        for (auto it : pos) 
            if (it.second > 0) 
                return false;
        
        for (auto it : neg) 
            if (it.second > 0) 
                return false;
        
        return true;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/making-file-names-unique/">making file names unique</a></strong></summary>

```cpp
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> ans;
        unordered_map<string, int> map;

        for (const string& name : names) {
            if (map.find(name) == map.end()) {
                map[name] = 1;
                ans.push_back(name);
            } else {
                int count = map[name];
                while (map.find(name + "(" + to_string(count) + ")") != map.end()) 
                    count++;
            
                map[name] = count;
                string newName = name + "(" + to_string(count) + ")";
                ans.push_back(newName);
                map[newName] = 1;
            }
        }
        return ans;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/max-number-of-k-sum-pairs/">max number of k sum pairs</a></strong></summary>

```cpp
class Solution {
public:
    int maxOperations(vector<int>& n, int k) {
        int count = 0;
        sort(n.begin(), n.end());
        int p = 0, q = n.size() - 1;
        
        while (q > p) {
            if ((n[p] + n[q]) == k) {
                count++;
                p++;
                q--;
            } else if ((n[p] + n[q]) < k) {
                p++;
            } else {
                q--;
            }
        }
        return count;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/count-good-meals/">count good meals</a></strong></summary>

```cpp
class Solution {
public:
    int countPairs(vector<int>& deliciousness) 
    {
        unordered_map<int,long long int> map1;
        sort(deliciousness.begin(),deliciousness.end());
        long long int count = 0;

        for(int x : deliciousness)
        {
            if(x!=0)
            {
                double num = log2(x); 
                if(floor(num) == num)
                    count += map1[0];
                
                int y = pow(2, floor(num) + 1);
                count += map1[y - x];
            }
            map1[x]++;
        }
        return count % (int)(1e9 + 7);
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/avoid-flood-in-the-city/">avoid flood in the city</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains)
    {
        int n = rains.size();
        vector<int> res(n, -1);
        unordered_map<int, int> mp;
        set<int> ss;

        for(int i = 0; i < n; i++) {
            if(rains[i]==0) {
                ss.insert(i);
                res[i] = 1;
            } else {
                if(mp.count(rains[i])) {
                    int lastIndex = mp[rains[i]];
                    auto index = ss.upper_bound(lastIndex);
                    if(index == ss.end())
                        return {};

                    res[*index] = rains[i];
                    ss.erase(index);
                }
                mp[rains[i]] = i;
            }
        }   
        return res;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/fraction-to-recurring-decimal/">fraction to recurring decimal</a></strong></summary>

```cpp
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";

        string result;
        if (numerator > 0 ^ denominator > 0)
            result += "-";
        
        long nume = labs(numerator);
        long denomi = labs(denominator);
        long quotient = nume / denomi;
        long remainder = nume % denomi;
        result += to_string(quotient);

        if (remainder == 0)
            return result;

        result += ".";
        unordered_map<long, int> remainderMap;
        while (remainder != 0) {
            if (remainderMap.find(remainder) != remainderMap.end()) {
                result.insert(remainderMap[remainder], "(");
                result += ")";
                break;
            }
            
            remainderMap[remainder] = result.size();
            remainder *= 10;
            quotient = remainder / denomi;
            result += to_string(quotient);
            remainder = remainder % denomi;
        }
        return result;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/design-hashmap/">design hashmap</a></strong></summary>

```cpp
// using linkedlist
class MyNode {
public:
    pair<int,int> p;
    MyNode* next;

    MyNode(int key, int value) : p(key,value), next(nullptr) {}
};

class MyHashMap {
public:
    MyNode* head;
    MyHashMap() {
        head = new MyNode(-1,-1);
    }
    
    void put(int key, int value) {
        MyNode* newNode = new MyNode(key,value);
        MyNode* tmp = head;
        while(tmp -> next != nullptr) {
            if(tmp -> p.first == key) {
                tmp -> p.second = value;
                return;
            }
            tmp = tmp -> next;
        }

        if (tmp -> p.first == key) 
            tmp -> p.second = value;
        else 
            tmp -> next = new MyNode(key, value);
    }
    
    int get(int key) {
        MyNode* tmp = head;
        while(tmp != nullptr) {
            if(tmp -> p.first == key) 
                return tmp -> p.second;

            tmp = tmp -> next;
        }
        return -1;
    }
    
    void remove(int key) {
        MyNode* tmp = head;
        while(tmp -> next != nullptr) {
            if(tmp -> next -> p.first == key) {
                MyNode* nodeToDelete = tmp -> next;
                tmp -> next = tmp -> next -> next;
                delete nodeToDelete;
                return;
            }
            tmp = tmp -> next;
        }
    }
};
```
</details>