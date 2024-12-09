<details>
<summary><strong><a href = "https://leetcode.com/problems/count-substrings-that-differ-by-one-character/description/">1638. Count Substrings That Differ by One Character</a></strong></summary>

```cpp
class Solution {
public:
    int countSubstrings(string s, string t) {
        int l1 = s.size(), l2 = t.size(), ans = 0;

        for(int i = 0; i < l1; i++){
            for(int j = 0; j < l2; j++){
                bool flag = 0;
                int k = 0;

                while(i+k < l1 && j+k < l2){
                    if(s[i+k] != t[j+k]){
                        if(flag) 
                            break;
                            
                        flag = 1;
                        ans ++;
                    }
                    else if(flag) 
                        ans ++;

                    k++;
                }
            }
        }
        return ans;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/description/">1418. Display Table of Food Orders in a Restaurant</a></strong></summary>

```cpp
class Solution 
{
public:
    vector<vector<string>> displayTable(vector<vector<string>>& o) 
    {
        vector<vector<string>> ans;
        set<string> st;
        map<int, map<string, int>> nmp;  // nested map
        for(int i = 0;i < o.size() ;i++)
        {
            st.insert(o[i][2]);
            nmp[stoi(o[i][1])][o[i][2]]++;
        }

        vector<string>vec;
        vec.push_back("Table");
        for(auto it: st)
            vec.push_back(it);

        ans.push_back(vec);

        for(auto itr: nmp)
        {
            vector<string>vec;
            vec.push_back(to_string(itr.first));
            for(auto it: st)
            {
                if(itr.second.find(it)!=itr.second.end( )) 
                    vec.push_back(to_string(itr.second[it]));

                else
                    vec.push_back("0");
            }
            ans.push_back(vec);
        }
        return ans;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/count-primes/description/">204. Count Primes</a></strong></summary>

```cpp
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) 
            return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false; 

        for (int i = 2; i * i < n; ++i) 
            if (isPrime[i]) 
                for (int j = i * i; j < n; j += i) 
                    isPrime[j] = false;

        int primeCount = 0;
        for (int i = 2; i < n; ++i) 
            if (isPrime[i]) 
                ++primeCount;

        return primeCount;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/encode-and-decode-tinyurl/description/">535. Encode and Decode TinyURL</a></strong></summary>

```cpp
class Solution {
    unordered_map<string, string> longToShort;
    unordered_map<std::string, std::string> shortToLong;
    const string baseUrl  = "http://tinyurl.com/";
    int cnt = 0;

    string getUniqueKey() {
        return to_string(cnt++);
    }
public:

    string encode(string longUrl) {
        if (longToShort.find(longUrl) != longToShort.end()) 
            return longToShort[longUrl];

        string shortKey = getUniqueKey();
        string shortUrl = baseUrl + shortKey;

        longToShort[longUrl] = shortUrl;
        shortToLong[shortUrl] = longUrl;

        return shortUrl;
    }

    string decode(string shortUrl) {
        return shortToLong[shortUrl];
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/">1865. Finding Pairs With a Certain Sum</a></strong></summary>

```cpp
#include <vector>
#include <unordered_map>

class FindSumPairs {
private:
    vector<int> nums1, nums2;
    unordered_map<int, int> freqMap2; 

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1(nums1), nums2(nums2) {
        for (int num : nums2) 
            freqMap2[num]++;
    }

    void add(int index, int val) {
        int originalValue = nums2[index];
        freqMap2[originalValue]--;

        if (freqMap2[originalValue] == 0) 
            freqMap2.erase(originalValue); 
        
        nums2[index] += val;
        freqMap2[nums2[index]]++;
    }

    int count(int tot) {
        int count = 0;
        for (int num1 : nums1) {
            int complement = tot - num1;
            if (freqMap2.find(complement) != freqMap2.end()) 
                count += freqMap2[complement];
        }
        return count;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/">1072. Flip Columns For Maximum Number of Equal Rows</a></strong></summary>

```cpp
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternCount;
        int maxRows = 0;

        for (const auto& row : matrix) {
            string pattern;
            for (int j = 0; j < row.size(); ++j) 
                pattern += (row[j] == row[0]) ? '0' : '1';
            
            patternCount[pattern]++;
            maxRows = max(maxRows, patternCount[pattern]);
        }
        return maxRows;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/find-duplicate-file-in-system/description/">609. Find Duplicate File in System</a></strong></summary>

```cpp
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> contentToPaths;
        
        for (const string& path : paths) {
            stringstream ss(path);
            string directory;
            ss >> directory;  
            
            string file;
            while (ss >> file) {
                size_t openBracket = file.find('(');
                size_t closeBracket = file.find(')');
                string fileName = file.substr(0, openBracket);
                string fileContent = file.substr(openBracket + 1, closeBracket - openBracket - 1);
                string fullPath = directory + "/" + fileName;
                contentToPaths[fileContent].push_back(fullPath);
            }
        }
        
        vector<vector<string>> duplicates;
        for (const auto& entry : contentToPaths) 
            if (entry.second.size() > 1) 
                duplicates.push_back(entry.second);
            
        return duplicates;
    }
};
```