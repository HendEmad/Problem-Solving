class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j, unordered_set<int>& island) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return;
        }
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
                    if (isSubIsland) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};