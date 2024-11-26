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
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;
        
        visited[0] = true;
        q.push(0);
        
        while (!q.empty()) {
            int room = q.front();
            q.pop();
            
            for (int key : rooms[room]) 
                if (!visited[key]) {
                    visited[key] = true;
                    q.push(key);
                }
        }
        
        for (bool v : visited) 
            if (!v) 
                return false;
        
        return true;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/redundant-connection/>redundant connection</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        
        for (int i = 1; i <= n; ++i) 
            parent[i] = i;

        function<int(int)> find = [&](int node) -> int {  // -> return type
            if (parent[node] != node)
                parent[node] = find(parent[node]); // find calls itself recursively; needs access to the actual array
            return parent[node];
        };

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            int rootU = find(u), rootV = find(v);
            if (rootU == rootV) 
                return edge; 
            parent[rootU] = rootV; 
        }
        return {};
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/count-servers-that-communicate/>count servers that communicate	</a></strong></summary>

```cpp
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rowCount(m, 0), colCount(n, 0);
        int totalServers = 0;

        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                    totalServers++;
                }

        int isolatedServers = 0;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (grid[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1) 
                    isolatedServers++;

        return totalServers - isolatedServers;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/map-of-highest-peak/>map of highest peak</a></strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.push({i, j});
                }

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && height[nx][ny] == -1) {
                    height[nx][ny] = height[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return height;
    }
};
```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/path-with-minimum-effort/>path with minimum effort</a></strong></summary>

```cpp
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [currEffort, cell] = pq.top();
            pq.pop();

            int x = cell.first, y = cell.second;
            if (x == rows - 1 && y == cols - 1) 
                return currEffort;

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    int newEffort = max(currEffort, abs(heights[nx][ny] - heights[x][y]));
                    if (newEffort < effort[nx][ny]) {
                        effort[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
        }
        return 0;
    }
};
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