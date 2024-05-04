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
