class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int turns) {
        int row = grid.size()  - 1; 
        int col = grid[0].size() - 1;
        
        for(int k = 0; k < turns; k++){
            for(int i = row; i > 0; i--){
                for(int j = col; j > 0;  j--){
                    swap(grid[i][j], grid[i][j-1]);
                }
                swap(grid[i-1][col], grid[i][0]);
            
            }
            for(int i = col; i > 0; i--)
                swap(grid[0][i], grid[0][i-1]);
        
        }
        
        return grid;
    }
};

/*
    Complexity analysis:
    Time: O(m.n.k), where 'm','n' and 'k' are the rows, columns, and the number of shift of the given matrix respectively.
    Space: O(1), since we did not use any extra spacethroughout the entire program.
*/
