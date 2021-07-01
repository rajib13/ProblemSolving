class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(grid[0][0] == 1) return 0; // if start point is an obstacle. 
        
        vector<vector<long>> dp(row, vector<long> (col, 0)); 
        dp[0][0] = 1; 
        
        // Fill the  first column with 1 until approaching an obstacle and after that with 0. 
        int value = 1;
        for(int r = 1; r < row; r++){
            if(grid[r][0] == 1) value = 0; 
            dp[r][0] = value;
        }
        // Similarly, Fill the first row.
        value = 1;
        for(int c = 1; c < col; c++){
            if(grid[0][c] == 1) value = 0; 
            dp[0][c] = value;
        }
        
        for(int r = 1; r < row; r++){
            for(int c = 1; c < col; c++){
                dp[r][c] = grid[r][c] == 1 ? 0 : dp[r-1][c] + dp[r][c-1]; // DP Logic
            }
        }
        return dp[row-1][col-1];
    }
};

/*
    Complexity analysis: 
    Time: O(m*n), where `m` and `n` are the number of rows and cols in the given grid, respectively, 
          as we need scan every element of the grid.
    Space: O(mn), since we use an auxiliary space to to store the intemediate results. 
*/
