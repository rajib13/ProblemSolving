class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int row = rows - 1, col = 0;
        int count = 0;
        
        while(row >= 0 and col < cols){
            if(grid[row][col] < 0) {
                row--;
                count += cols - col;
            } else col++;
        }
        return count;
    }
};

/*
	Complexity analysis:
	Time: O(r + c), where `r` and `c` are the number of rows and cols.
	Space: O(1), since we do not use any extra space;
*/
