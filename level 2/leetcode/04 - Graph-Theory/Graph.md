<details>
  <summary><strong><a href=https://leetcode.com/problems/find-the-town-judge/description/>Find the Town Judge</a></strong></summary>

```cpp
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n + 1, 0);
        for (auto& t : trust) {
            trustCount[t[0]]--; 
            trustCount[t[1]]++; 
        }

        for (int i = 1; i <= n; ++i) 
            if (trustCount[i] == n - 1) 
                return i; 

        return -1;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/find-center-of-star-graph/>find center of star graph</a></strong></summary>

```cpp
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) ?
                edges[0][0] : edges[0][1];
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/>minimum number of vertices to reach all nodes</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> hasIncoming(n, false);
        for (const auto& edge : edges) 
            hasIncoming[edge[1]] = true;
        
        vector<int> result;
        for (int i = 0; i < n; ++i) 
            if (!hasIncoming[i]) 
                result.push_back(i);
        
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/sort-integers-by-the-power-value/>sort integers by the power value</a></strong></summary>

```cpp
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        auto power = [](int x) {
            int steps = 0;
            while (x != 1) {
                if (x % 2 == 0) 
                    x /= 2;
                else 
                    x = 3 * x + 1;
                
                ++steps;
            }
            return steps;
        };
        
        vector<pair<int, int>> nums;
        for (int i = lo; i <= hi; ++i) 
            nums.emplace_back(power(i), i);
        
        sort(nums.begin(), nums.end());
        return nums[k - 1].second;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/regions-cut-by-slashes/>regions cut by slashes</a></strong></summary>

```cpp
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int size = n * n * 4; 
        vector<int> parent(size);

        for (int i = 0; i < size; ++i) 
            parent[i] = i;

        auto find = [&](int x) {
            while (x != parent[x]) {
                parent[x] = parent[parent[x]]; 
                x = parent[x];
            }
            return x;
        };

        auto unite = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) 
                parent[rootX] = rootY;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int base = (i * n + j) * 4;
                
                if (grid[i][j] == ' ') {
                    unite(base, base + 1);
                    unite(base + 1, base + 2);
                    unite(base + 2, base + 3);
                } else if (grid[i][j] == '/') {
                    unite(base, base + 3);
                    unite(base + 1, base + 2);
                } else if (grid[i][j] == '\\') {
                    unite(base, base + 1);
                    unite(base + 2, base + 3);
                }

                if (i > 0) 
                    unite(base, ((i - 1) * n + j) * 4 + 2);
                
                if (j > 0) 
                    unite(base + 3, (i * n + (j - 1)) * 4 + 1);
            }
        }

        int regions = 0;
        for (int i = 0; i < size; ++i) 
            if (find(i) == i) 
                ++regions;

        return regions;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/keys-and-rooms/>keys and rooms</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/parallel-courses/>parallel courses</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/connecting-cities-with-minimum-cost/>connecting cities with minimum cost</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/redundant-connection/>redundant connection</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/shortest-path-to-get-food/>shortest path to get food</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/count-servers-that-communicate/>count servers that communicate	</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/map-of-highest-peak/>map of highest peak</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/path-with-minimum-effort/>path with minimum effort</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/is-graph-bipartite/>is graph bipartite</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/minimum-path-cost-in-a-hidden-grid/>minimum path cost in a hidden grid</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/maximal-network-rank/>maximal network rank</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/path-with-maximum-minimum-value/>path with maximum minimum value</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/find-eventual-safe-states/>find eventual safe states</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/pyramid-transition-matrix/>pyramid transition matrix</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/>most stones removed with same row or column</a></strong></summary>

```cpp

```
</details>