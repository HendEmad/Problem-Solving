<details>
<summary><strong><a href = "https://leetcode.com/problems/friends-of-appropriate-ages/">528.friends of appropriate ages</a></strong></summary>

```
class Solution {
public:
    int numFriendRequests(std::vector<int>& ages) {
        int count = 0;
        unordered_map<int, int> ageCount;

        for (int age : ages) 
            ++ageCount[age];

        for (auto& person1 : ageCount) {
            for (auto& person2 : ageCount) {
                int age1 = person1.first;
                int age2 = person2.first;
                int count1 = person1.second;
                int count2 = person2.second;

                if (age2 <= 0.5 * age1 + 7) 
                    continue;
                
                if (age2 > age1) 
                    continue;
                
                if (age2 > 100 && age1 < 100) 
                    continue;

                if (age1 == age2) 
                    count += count1 * (count2 - 1);
                else 
                    count += count1 * count2;
            }
        }

        return count;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/magic-squares-in-grid/">840.magic squares in grid</a></strong></summary>

```
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i <= rows - 3; ++i) {
            for (int j = 0; j <= cols - 3; ++j) 
                if (isMagicSquare(grid, i, j)) 
                    ++count;
        }

        return count;
    }

    bool isMagicSquare(const std::vector<std::vector<int>>& grid, int row, int col) {
        vector<bool> seen(10, false);  

        for (int i = row; i < row + 3; ++i) {
            for (int j = col; j < col + 3; ++j) {
                int num = grid[i][j];
                if (num < 1 || num > 9 || seen[num]) 
                    return false;
                
                seen[num] = true;
            }
        }

        int targetSum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
        for (int i = row + 1; i < row + 3; ++i) {
            int sum = 0;
            for (int j = col; j < col + 3; ++j) 
                sum += grid[i][j];
            
            if (sum != targetSum) 
                return false;
            
        }
        for (int j = col; j < col + 3; ++j) {
            int sum = 0;
            for (int i = row; i < row + 3; ++i) 
                sum += grid[i][j];
            
            if (sum != targetSum) 
                return false;
            
        }
        if (grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] != targetSum) 
            return false;
        
        if (grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col] != targetSum) 
            return false;
        

        return true;
    }    
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/snapshot-array/">1146.snapshot array</a></strong></summary>

```
class SnapshotArray {
private:
    vector <unordered_map<int, int>> listOfVersions;

public:
    // Solution using list of hash maps
    SnapshotArray(int length) {
        listOfVersions.emplace_back();    
    }
    
    void set(int index, int val) {
        int snapId = listOfVersions.size() - 1;
        listOfVersions[snapId][index] = val;
    }
    
    int snap() {
        listOfVersions.emplace_back();
        return listOfVersions.size() - 2;
    }
    
    int get(int index, int snapId) {
        for(int i = snapId; i >= 0; i--){
            if(listOfVersions[i].count(index))
                return listOfVersions[i][index];
        }
        return 0;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/can-make-palindrome-from-substring/">1177.can make palindrome from substring</a></strong></summary>

```
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> ret;
        vector<vector<int>> prefix;
        vector<int> temp(26, 0);

        prefix.push_back(temp);

        for(int i=0; i<s.length(); i++)
        {
            temp[s[i]-'a']++;
            prefix.push_back(temp);
        }
        
        for(int i=0; i<queries.size(); i++)
        {
            int hi = queries[i][1], lo = queries[i][0], k = queries[i][2];
            vector<int> sub = prefix[hi+1];
            int odd=0, sum=hi-lo+1;

            for(int j=0; j<26; j++)
            {
                sub[j] = sub[j] - prefix[lo][j];
                odd+=sub[j]%2;
            }
            
            bool t = (odd <= k*2 + sum%2);
            ret.push_back(t);
        }
        
        return ret;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/k-diff-pairs-in-an-array/">532.k diff pairs in an array</a></strong></summary>

```
class Solution {
public:

int bs(vector<int>&nums,int start, int x){
    int end = nums.size()-1;

    while(start<=end){
        int mid = (start+end)/2;

        if(nums[mid]==x)
            return mid;

        else if(x>nums[mid])
            start = mid+1;

        else
            end = mid-1;
    }

    return -1;
}


    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        set<pair<int,int>> ans;

        for(int i=0;i<nums.size();i++)
            if(bs(nums,i+1,nums[i]+k)!=-1)
                ans.insert({nums[i],nums[i]+k});

        return ans.size();
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/">1465.maximum area of a piece of cake after horizontal and vertical cuts</a></strong></summary>

```
class Solution {
public:
    const int MOD = 1e9 + 7;

    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int maxHorizontal = max(horizontalCuts[0], h - horizontalCuts.back());
        int maxVertical = max(verticalCuts[0], w - verticalCuts.back());

        for (int i = 1; i < horizontalCuts.size(); i++) 
            maxHorizontal = max(maxHorizontal, horizontalCuts[i] - horizontalCuts[i - 1]);

        for (int i = 1; i < verticalCuts.size(); i++) 
            maxVertical = max(maxVertical, verticalCuts[i] - verticalCuts[i - 1]);

        long long maxArea = static_cast<long long>(maxHorizontal) * maxVertical;

        return maxArea % MOD;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/beautiful-arrangement-ii/">667.beautiful arrangement ii</a></strong></summary>

```
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector <int> answer(n);

        int left = 1, right = n;
        
        for(int i = 0; i < n; i++){
            if(k > 1){
                answer[i] = (k % 2 == 0) ? right-- : left++;
                k--;
            }
            else
                answer[i] = left++;
        }

        return answer;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/shortest-unsorted-continuous-subarray/">581.shortest unsorted continuous subarray</a></strong></summary>

```
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1, end = -2;
        int minval = nums[n - 1], maxval = nums[0];

        for(int i = 1; i < n; i++){
            maxval = max(maxval, nums[i]);
            minval = min(minval, nums[n - 1 - i]);

            if(nums[i] < maxval)
                end = i;
            
            if(nums[n - 1 - i] > minval)
                start = n - 1 - i;
        }

        return end - start + 1;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/invalid-transactions/">1169.invalid transactions</a></strong></summary>

```
class Solution {
public:

    struct transaction{
        string name;
        int time;
        int amount;
        string city;

        bool operator==(const transaction& other) const{
        return name == other.name && time == other.time && amount == other.amount && city == other.city;
        }
    };

    vector<string> invalidTransactions(vector<string>& transactions) {
        vector <transaction> parsedTransactions;
        vector <bool> isInvalid(transactions.size(), false);
        unordered_map <string, vector <transaction>> nameToTransactions;

        // parse transactions; store then in a vector of transactions objects;
        for(const string& transaction: transactions){
            size_t pos = 0; 
            size_t found = transaction.find(',', pos);
            string name = transaction.substr(pos, found - pos);
            pos = found + 1;

            found = transaction.find(',', pos);
            int time = stoi(transaction.substr(pos, found - pos));
            pos = found + 1;

            found = transaction.find(',', pos);
            int amount = stoi(transaction.substr(pos, found - pos));
            pos = found + 1;

            string city = transaction.substr(pos);
            parsedTransactions.push_back({name, time, amount, city});
            nameToTransactions[name].push_back({name, time, amount, city});
        }    

        // invalid transactions
        for(int i = 0; i < parsedTransactions.size(); i++){
            const transaction& curr = parsedTransactions[i];

            if(curr.amount > 1000)
                isInvalid[i] = true;

            vector <transaction>& sameNameTransactions = nameToTransactions[curr.name];

            for(const transaction& other: sameNameTransactions){
                if(other.city != curr.city && abs(other.time - curr.time) <= 60){
                    isInvalid[i] = true;
                    isInvalid[distance(parsedTransactions.begin(), find(parsedTransactions.begin(), parsedTransactions.end(), other))] = true;
                }
            }
        }

        // collect invalid transactions as stirngs
        vector <string> result;
        for(int i = 0; i < transactions.size(); i++)
            if(isInvalid[i])
                result.push_back(transactions[i]);

        return result;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/circular-array-loop/">457.circular array loop</a></strong></summary>

```
class Solution {
public:
    int next(const vector<int>& nums, int i){
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
                continue;

            int slow = i, fast = i;

            while(nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(nums, fast)] > 0){
                slow = next(nums, slow);
                fast = next(nums, next(nums, fast));

                if(slow == fast){
                    if(slow == next(nums, slow))
                        break;
                    return true;
                }
            }

            slow = i;
            int val = nums[slow];

            while(nums[slow] * val > 0){
                int nextIndex = next(nums, slow);
                nums[slow] = 0;
                slow = nextIndex;
            }
        }
        return false;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/non-decreasing-array/">665.non decreasing array</a></strong></summary>

```
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0; //to store the count of modifications                   
        for(int i = 1; i < nums.size(); i++){

            //decreasing sequence found
            if(nums[i] < nums[i-1]){

                //if count after increasing becomes more than 1 then false
                if(++cnt > 1) return false;
                
                //in case of the 2nd element as i[1] < i[0] so make i[0] = i[1]
                //if prev of prev element of curr is less than or equal to it then only the we can make it non decreasing by making the greater equal to lesser (prev = curr).
                if(i == 1 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];    
                
                //if prev of prev is greater than curr then we have to make the lesser equal to greater (curr = prev)
                else 
                    nums[i] = nums[i-1];
            }
        }
        
        //this command will only run if the loop is totally traversed and count <= 1 so return true.
        return true;
    } 
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/">1010.pairs of songs with total durations divisible by 60</a></strong></summary>

```
class Solution{
public:
    int numPairsDivisibleBy60(vector<int>& time)
    {
        int count=0;
        vector<int>v(60,0);

        for(int i=0;i<time.size();i++)
        {
            int a=time[i]%60;
            if(a==0)
                count+=v[0];
            else
                count+=v[60-a];
            v[a]++;
        }

        return count;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/">1524.number of sub arrays with odd sum</a></strong></summary>

```
class Solution {
    const int MOD = 1e9 + 7;
public:
    int numOfSubarrays(vector<int>& arr) {
        long long even = 0, pre = 0, res = 0;

        for (int i = 0; i < arr.size(); i++) {
            even += !(pre & 1);
            pre += arr[i];
            auto is_odd = (pre % 2 == 1);
            res = (res + (is_odd ? even: i + 1 - even)) % MOD;
        }
        
        return res;
    }
};
```
</details>