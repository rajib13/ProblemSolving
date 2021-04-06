class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(i == 0 and j > 0) grid[i][j] += grid[i][j-1]; // In frist row, jsut add the columns up. 
                else if(j == 0 and i > 0) grid[i][j] += grid[i-1][j]; // In first column, add the rows up. 
                else if(i > 0 and j > 0) grid[i][j] += min(grid[i-1][j], grid[i][j-1]); // in general case. 
            }
        }
        return grid[row-1][col-1];
    }
};

/*
    Complexity Analysis:
    Time: O(mn), as we need to scan all elements of the given grid. 
    Space: O(1), as we do not use any extra space.
*/
