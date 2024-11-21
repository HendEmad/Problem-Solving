<details>
<summary><strong><a href = "https://leetcode.com/problems/count-sub-islands/">1905.count sub islands</a></strong></summary>

```cpp
class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j, unordered_set<int>& island) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) 
            return;
        
        island.insert(i * n + j);
        grid[i][j] = 0;
        dfs(grid, i + 1, j, island);
        dfs(grid, i - 1, j, island);
        dfs(grid, i, j + 1, island);
        dfs(grid, i, j - 1, island);
    }    

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        int count = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    // Store the coordinates of the island in grid2
                    unordered_set<int> island;
                    dfs(grid2, i, j, island);
                    
                    // Check if it's a sub-island
                    bool isSubIsland = true;
                    for (int cell : island) {
                        int x = cell / n, y = cell % n;
                        if (grid1[x][y] != 1) {
                            isSubIsland = false;
                            break;
                        }
                    }
                    
                    // Increment count if it's a sub-island
                    if (isSubIsland) 
                        count++;
                }
            }
        }
        return count;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/min-cost-to-connect-all-points/">1584.min cost to connect all points</a></strong></summary>

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n), components(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
            components[i] = 1;
        }
    }
    
    int find(int x) {
        if (x != parent[x]) 
            parent[x] = find(parent[x]);
        
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                components[rootY] += components[rootX];
            } 
            else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                components[rootX] += components[rootY];
            } 
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
                components[rootX] += components[rootY];
            }
        }
    }
    
    int getComponents(int x) {
        return components[find(x)];
    }
    
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> components;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> dist(n, vector<int>(n));
        
        // Compute Manhattan distance between each pair of points
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                dist[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                dist[j][i] = dist[i][j]; // Symmetric matrix
            }
        }
        
        // Kruskal's algorithm to find MST
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < n; ++i) 
            for (int j = i + 1; j < n; ++j) 
                edges.push_back({dist[i][j], {i, j}});
            
        sort(edges.begin(), edges.end());
        
        UnionFind uf(n);
        int minCost = 0, numEdges = 0;
        for (const auto& edge : edges) {
            int weight = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            if (uf.find(u) != uf.find(v)) {
                uf.unite(u, v);
                minCost += weight;
                numEdges++;
                if (numEdges == n - 1) 
                    break; // MST has n - 1 edges
            }
        }
        
        return minCost;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/range-sum-query-mutable/">307.range sum query mutable</a></strong></summary>

```cpp
class NumArray {
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        st.resize(4 * n);
        build(nums, 0, 0, n - 1);
    }
    
    void update(int index, int val) {
        update(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return sumRange(0, 0, n - 1, left, right);
    }
    
private:
    vector<int> st;
    int n;
    
    void build(vector<int>& nums, int v, int tl, int tr) {
        if (tl == tr) 
            st[v] = nums[tl];
        else {
            int tm = tl + (tr - tl) / 2;
            build(nums, 2 * v + 1, tl, tm);
            build(nums, 2 * v + 2, tm + 1, tr);
            st[v] = st[2 * v + 1] + st[2 * v + 2];
        }
    }
    
    void update(int v, int tl, int tr, int index, int val) {
        if (tl == tr) {
            st[v] = val;
        } else {
            int tm = tl + (tr - tl) / 2;
            if (index <= tm) 
                update(2 * v + 1, tl, tm, index, val);
            else 
                update(2 * v + 2, tm + 1, tr, index, val);
            
            st[v] = st[2 * v + 1] + st[2 * v + 2];
        }
    }
    
    int sumRange(int v, int tl, int tr, int left, int right) {
        if (left > right) 
            return 0;
        if (left == tl && right == tr) 
            return st[v];
        
        int tm = tl + (tr - tl) / 2;
        return sumRange(2 * v + 1, tl, tm, left, min(right, tm)) +
               sumRange(2 * v + 2, tm + 1, tr, max(left, tm + 1), right);
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/search-suggestions-system/">1268.search suggestions system</a></strong></summary>

```cpp
class TrieNode {
public:
    vector<TrieNode*> children;
    vector<string> suggestions;
    
    TrieNode() : children(26, nullptr) {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) 
                node->children[idx] = new TrieNode();
            
            node = node->children[idx];
            node->suggestions.push_back(word);
            sort(node->suggestions.begin(), node->suggestions.end());
            if (node->suggestions.size() > 3) 
                node->suggestions.pop_back();
        }
    }
    
    vector<string> search(const string& prefix) {
        TrieNode* node = root;
        vector<string> result;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!node->children[idx]) 
                return result;
            
            node = node->children[idx];
        }
        return node->suggestions;
    }
    
private:
    TrieNode* root;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        for (const string& product : products) 
            trie.insert(product);
        
        vector<vector<string>> result;
        string prefix = "";
        for (char ch : searchWord) {
            prefix += ch;
            result.push_back(trie.search(prefix));
        }
        
        return result;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/lexicographical-numbers/">386.lexicographical numbers</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int curr = 1;
        for (int i = 1; i <= n; ++i) {
            result.push_back(curr);
            if (curr * 10 <= n) 
                curr *= 10;
            else if (curr % 10 != 9 && curr + 1 <= n) 
                curr++;
            else {
                while ((curr / 10) % 10 == 9) 
                    curr /= 10;
                
                curr = curr / 10 + 1;
            }
        }
        return result;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/short-encoding-of-words/">820.short encoding of words</a></strong></summary>

```cpp
class Solution {
public:
    struct Trie {
     unordered_map<char, Trie*> childs;   
    };

    Trie* root = nullptr;
    int cnt_sharp = 0;
    int cnt_char = 0;
    Solution() : root(new Trie()) {};


    void buildSuffixTrie(string word) {
        auto current = root;
        for (int i = word.size() - 1; i >= 0; i--) {
            char c = word[i];
            if (current->childs.find(c) != current->childs.end()) 
                current = current->childs[c];
            else {
                if (current->childs.find('*') != current->childs.end()) {
                    current->childs.erase('*');
                    cnt_char -= (word.size() - i - 1);
                    cnt_sharp--;
                }
                current->childs[c] = new Trie();
                current = current->childs[c];
            }
            cnt_char++;
        }
        if (current->childs.size() == 0) {
            current->childs['*'] = nullptr;
            cnt_sharp++;
        } 
        else 
            cnt_char -= word.size();
    }

    int minimumLengthEncoding(vector<string>& words) {
        for (const auto & word : words) 
            buildSuffixTrie(word);

      return cnt_char + cnt_sharp;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/valid-tic-tac-toe-state/">794.valid tic tac toe state</a></strong></summary>

```cpp
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int countX = 0, countO = 0;
        for (const string& row : board) {
            for (char c : row) {
                if (c == 'X') 
                    countX++;
                else if (c == 'O')  
                    countO++;
            }
        }
        if (countX != countO && countX != countO + 1) 
            return false; // Invalid count of 'X' and 'O'
        if (win(board, 'X') && countX != countO + 1) 
            return false; // 'X' wins but 'O' has more turns
        if (win(board, 'O') && countX != countO) 
            return false; // 'O' wins but 'X' has more turns

        return true;
    }
    
    bool win(const vector<string>& board, char player) {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)    
                return true; // Check rows
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player)    
                return true; // Check columns
        }

        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) 
            return true; // Check diagonal
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) 
            return true; // Check reverse diagonal
        
        return false;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/camelcase-matching/">1023.camelcase matching</a></strong></summary>

```cpp
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        for (const auto& query : queries) 
            result.push_back(isMatch(query, pattern));
        
        return result;
    }
    
    bool isMatch(const string& query, const string& pattern) {
        int queryPtr = 0, patternPtr = 0;
        while (queryPtr < query.size() && patternPtr < pattern.size()) {
            if (query[queryPtr] == pattern[patternPtr]) {
                queryPtr++;
                patternPtr++;
            } 
            else if (isupper(query[queryPtr])) 
                return false;
            
            else 
                queryPtr++;
        }
        if (patternPtr != pattern.size()) 
            return false;
        
        while (queryPtr < query.size()) {
            if (isupper(query[queryPtr]))   
                return false;
            
            queryPtr++;
        }
        return true;
    }
};
```
</details>

<details>
<summary><strong><a href = "">677.map sum pairs</a></strong></summary>

```cpp
class TrieNode {
public:
    int value;
    unordered_map<char, TrieNode*> children;
    
    TrieNode() : value(0) {}
};

class MapSum {
private:
    TrieNode* root;
    unordered_map<string, int> keyValue;

public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        int delta = val - keyValue[key];
        keyValue[key] = val;
        
        TrieNode* curr = root;
        for (char ch : key) {
            if (!curr->children.count(ch)) 
                curr->children[ch] = new TrieNode();
            
            curr = curr->children[ch];
            curr->value += delta;
        }
    }
    
    int sum(string prefix) {
        TrieNode* curr = root;
        for (char ch : prefix) {
            if (!curr->children.count(ch)) 
                return 0;
            
            curr = curr->children[ch];
        }
        return curr->value;
    }
};
```
</details>