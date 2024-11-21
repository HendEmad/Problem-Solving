<details>
<summary><strong><a href = "https://leetcode.com/problems/minimum-area-rectangle/">minimum area rectangle</a></strong></summary>

```cpp
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> pointSet;
        for (const auto& p : points) 
            pointSet.insert(p[0] * 40001 + p[1]);

        int minArea = INT_MAX;
        int n = points.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (points[i][0] == points[j][0] or points[i][1] == points[j][1]) 
                    continue;
                
                if (pointSet.count(points[i][0] * 40001 + points[j][1]) and 
                    pointSet.count(points[j][0] * 40001 + points[i][1])) {
                    
                    int area = abs(points[i][0] - points[j][0]) * 
                    abs(points[i][1] - points[j][1]);
                    minArea = min(minArea, area);
                }
            }
        }
        return minArea == INT_MAX ? 0 : minArea;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/vowel-spellchecker/">vowel spellchecker</a></strong></summary>

```cpp
class Solution {
public:
    string to_lower(string s) {        
        for(char &c : s)
            c = tolower(c);
        return s;
    }

    vector<string> spellchecker(vector<string>& A, vector<string>& Q) {
        unordered_set<string> hs;
        unordered_map<string, string> hm1;
        unordered_map<string, string> hm2;
        
        unordered_set<char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');
        
        for(string w : A) {
            hs.insert(w);
            
            string wLower = to_lower(w);
            if(!hm1.count(wLower)) 
                hm1[wLower] = w;

            string cur = "";
            for(auto ch : wLower) {
                if(vowels.count(ch)) 
                    cur += '*';
                else 
                    cur += ch;
            }

            if(!hm2.count(cur)) 
                hm2[cur] = w;
        }

        vector<string> v;
        for(auto q : Q) {
            string qLower = to_lower(q);
            if(hs.count(q)) 
                v.push_back(q);

            else if(hm1.count(qLower)) 
                v.push_back(hm1[qLower]);

            else {
                string cur = "";
                for(auto ch : qLower) {
                    if(vowels.count(ch)) 
                        cur += '*';
                    else 
                        cur += ch;
                }

                if(hm2.count(cur)) 
                    v.push_back(hm2[cur]);
                else 
                    v.push_back("");
            }
        }
        return v;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/brick-wall/">brick wall</a></strong></summary>

```cpp
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        vector<vector<int>> pre;

        for(int i = 0; i < wall.size() ;i++){
             vector<int> sum(wall[i].size(), 0);
             sum[0] = wall[i][0];

            for(int j = 1; j < wall[i].size(); j++)
                sum[j] = sum[j - 1] + wall[i][j];

            pre.push_back(sum);
        }

        unordered_map<int,int> count;
        int maxi = 0;
        for(int i = 0; i < pre.size(); i++){
            for(int j = 0; j < pre[i].size() - 1; j++){
                cout<< pre[i][j]<< " ";
                count[pre[i][j]]++;
                maxi = max(maxi, count[pre[i][j]]);
            }
            cout<< endl;
        }

        cout<< maxi;
        return wall.size() - maxi;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/alphabet-board-path/">alphabet board path</a></strong></summary>

```cpp
class Solution {
public:
    string alphabetBoardPath(string target) {
        int row = 0, col = 0, i = 0, n = target.size();
        string ans = "";

        while(i < n){
            char ch = target[i];
            int n = ch - 'a', r = n / 5, c = n % 5;

            if(ch == 'z'){
                while(c < col) 
                    ans += 'L', col--;
                while(c > col) 
                    ans += 'R', col++;
                while(r > row) 
                    ans += 'D', row++;
                while(r < row) 
                    ans += 'U', row--;
            }

            else{
                while(r > row) 
                    ans += 'D', row++;
                while(r < row) 
                    ans += 'U', row--;
                while(c < col) 
                    ans += 'L', col--;
                while(c > col) 
                    ans += 'R', col++;
            }

            ans += '!';
            i++;

            while(i < n && target[i] == ch) 
                ans += '!', i++;
        }
        return ans;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/subarray-sums-divisible-by-k/">subarray sums divisible by k</a></strong></summary>

```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       unordered_map<int, int> mp;
       mp[0] = 1;
       int sum = 0, count = 0;

       for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        int div = sum % k;
        if(div < 0)   
            div += k;

        if(mp.find(div) != mp.end())
            count += mp[div];
        
        mp[div]++;
       }
        return count;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/design-authentication-manager/">design authentication manager</a></strong></summary>

```cpp
class AuthenticationManager {
public:
    unordered_map<string,pair<int,int>>m;
    int ttl = 0;

    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        m[tokenId] = {currentTime, currentTime + ttl};
    }
    
    void renew(string tokenId, int currentTime) {
        if(m.find(tokenId) != m.end()) 
            if(currentTime< m[tokenId].second)
                m[tokenId] = {currentTime, currentTime + ttl};
    }
    
    int countUnexpiredTokens(int currentTime) {
        int c = 0;
        for(auto it = m.begin();it!=m.end();it++)
            if(it->second.first<=currentTime && it->second.second>currentTime)
                c++;

        return c;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/">evaluate the bracket pairs of a string</a></strong></summary>

```cpp
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mapKnowledge;
        string replaced;

        for (auto& k : knowledge)
            mapKnowledge[k[0]] = k[1];

        int start = -1;
        string key;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') 
                start = i;
            else if (start < 0)
                replaced.push_back(s[i]);
            else if (s[i] == ')') {
                key = s.substr(start+1, i-start-1);
                start = -1;
                if (mapKnowledge.count(key))
                    replaced.append(mapKnowledge[key]);
                else
                    replaced.push_back('?');
            } 
        }
        return replaced;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/binary-subarrays-with-sum/description/">Binary Subarrays With Sum</a></strong></summary>

```cpp
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> count;
        count[0] = 1;
        int curr_sum = 0;
        int total_subarrays = 0;

        for (int num : nums) {
            curr_sum += num;
            if (count.find(curr_sum - goal) != count.end()) 
                total_subarrays += count[curr_sum - goal];
            
            count[curr_sum]++;
        }

        return total_subarrays;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/contiguous-array/">Contiguous Array</a></strong></summary>

```cpp
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int one = 0;
        int result = 0;
        unordered_map<int, int> count; // Map the difference to the ending index of subarray
        count[0] = -1; // Initialize to handle the case when subarray starts from index 0

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) 
                zero++;
            else 
                one++;
            
            int diff = one - zero;
            if(count.find(diff) != count.end()) 
                result = max(result, i - count[diff]);
            else 
                count[diff] = i;
        }
        return result;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/bulls-and-cows/">Bulls and Cows</a></strong></summary>

```cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        int cowCnt = 0;
        for(int i = 0; i < secret.size(); i++)
            if(secret[i] == guess[i])
                cowCnt++;

        int bullCnt = 0;
        unordered_map<char,int> m;

        for(int i = 0; i < secret.size(); i++)
            m[secret[i]]++;

        for(int i = 0; i < guess.size(); i++){
            if(m.find(guess[i]) != m.end() && m[guess[i]] > 0){
                bullCnt++;
                m[guess[i]]--;
            }
        }
        bullCnt -= cowCnt;

        string a = to_string(cowCnt);
        string b = to_string(bullCnt);

        string s = "";
        s = s + a;
        s.push_back('A');
        s = s + b;
        s.push_back('B');
        return s;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/powerful-integers/description/">Powerful Integers</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        map<int,int> mp;

        for(int i = 0; i <= log(bound) / log(x); i++){
            int b = 0;
            
            while(b <= log(bound) / log(y)){
                int f = pow(x, i) + pow(y, b);
                if(f <= bound && mp.find(f) == mp.end()){
                    mp[f] = 1;
                    ans.push_back(f);
                }
                else if(x == 1 || y == 1)
                    break;
                
                b+=1;
            }

            if(x == 1)
                break;
        }
        return ans;
    }
};
```
</details>


<details>
<summary><strong><a href = "https://leetcode.com/problems/repeated-dna-sequences/">Repeated DNA Sequences</a></strong></summary>

```cpp
// using sliding window approach

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        string win;
        unordered_set<string> allTens;
        unordered_set<string> ans;

        int N = s.size();
        N = min(N, 10);
        for (int i=0; i < N; i++)
            win.push_back(s[i]);
        
        allTens.insert(win);

        N = s.size();
        for (int i=10; i < N; i++){
            win.erase(win.begin());
            win.push_back(s[i]);

            if(allTens.count(win))
                ans.insert(win);
            else
                allTens.insert(win);
        }

        return vector(ans.begin(), ans.end());
    }
};
```