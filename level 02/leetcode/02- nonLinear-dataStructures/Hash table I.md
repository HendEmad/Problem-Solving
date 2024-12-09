<details>
<summary><strong><a href = "https://leetcode.com/problems/design-hashset/">design hashset</a></strong></summary>

```cpp
class MyHashSet {
private:
    vector<bool> set;
public:
    MyHashSet() : set(1000001, false) {}
    
    void add(int key) {
        set[key] = true;
    }
    
    void remove(int key) {
        set[key] = false;
    }
    
    bool contains(int key) {
        return set[key];
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/uncommon-words-from-two-sentences/">uncommon words from two sentences</a></strong></summary>

```cpp
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;
        vector<string> res;
        string combined = s1 + " " + s2;

        stringstream ss(combined); // initialize string stream object with 'combined'
        string word;

        // iterate over words of the string stream one by one
        // >> extracts words separated by whitespaces.
        while(ss >> word)
            wordCount[word]++;

        // find words that appear just once
        for(auto& wc : wordCount) 
            if(wc.second == 1)
                res.push_back(wc.first);
        
        return res;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/rabbits-in-forest/">rabbits in forest</a></strong></summary>

```cpp
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> countMap;

        for(int ans : answers)
            countMap[ans]++;

        int totalRabbits = 0;

        for(const auto& cm : countMap) {
            int ans = cm.first;
            int cnt = cm.second;

            int groupSize = ans + 1;
            int compelteGroups = (cnt + groupSize - 1) / groupSize;
            totalRabbits += compelteGroups * groupSize;
        }
        return totalRabbits;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/implement-magic-dictionary/">implement magic dictionary</a></strong></summary>

```cpp
class MagicDictionary {
    unordered_set<string> words;
public:
    MagicDictionary() {}
    
    void buildDict(vector<string> dict) {
        for(const string& word : dict) 
            words.insert(word);
    }
    
    bool search(string searchWord) {
        int length = searchWord.length();
        for(const string& word : words) {
            if(word.length() != length) 
                continue;

            int diffCnt = 0;
            for(int i = 0; i < length; i++) {
                if(searchWord[i] != word[i]) {
                    ++diffCnt;
                    if(diffCnt > 1) 
                        break;
                }
            }

            if(diffCnt == 1)
                return true;
        }
        return false;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/find-the-difference/">find the difference</a></strong></summary>

```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt (26, 0);
        for(char c : s)
            cnt[c - 'a']++;
        
        for(char c : t) 
            cnt[c - 'a']--;

        for(int i = 0; i < 26; i++) 
            if(cnt[i] == -1)
                return 'a' + i;

        return '\0';
    }
};
```
</details>


<details>
<summary><strong><a href = "shortest completing word">shortest completing word</a></strong></summary>

```cpp
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> licenseCount;
    
        for (char c : licensePlate) {
            if (isalpha(c)) {
                char lowerChar = tolower(c);
                licenseCount[lowerChar]++;
            }
        }
    
        string result;
        int minLength = INT_MAX;
        
        for (const string& word : words) {
            unordered_map<char, int> wordCount;
            for (char c : word) 
                wordCount[c]++;
            
            bool isCompleting = true;
            for (const auto& entry : licenseCount) {
                if (wordCount[entry.first] < entry.second) {
                    isCompleting = false;
                    break;
                }
            }
            
            if (isCompleting && word.length() < minLength) {
                result = word;
                minLength = word.length();
            }
        }
        return result;
    }
};
```
</details>

<details>
<summary><strong><a href = "tuple with same product">tuple with same product</a></strong></summary>

```cpp
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }
        
        int result = 0;
        for (auto& [product, count] : productCount) 
            if(count > 1)
                result += count * (count - 1) / 2 * 8;
        
        return result;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/number-of-boomerangs/">number of boomerangs</a></strong></summary>

```cpp
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int result = 0;
        
        for (const auto& p1 : points) {
            unordered_map<int, int> distCount;
            for (const auto& p2 : points) {
                if (p1 != p2) {
                    int dist = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
                    distCount[dist]++;
                }
            }
            
            for (const auto& entry : distCount) {
                int count = entry.second;
                result += count * (count - 1); 
            }
        }
        return result;
    }
};
```
</details>