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

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/>minimum number of vertices to reach all nodes</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/sort-integers-by-the-power-value/>sort integers by the power value</a></strong></summary>

```cpp

```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/regions-cut-by-slashes/>regions cut by slashes</a></strong></summary>

```cpp

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