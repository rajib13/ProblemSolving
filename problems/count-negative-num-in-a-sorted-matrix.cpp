class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int count = 0;
        int row = grid.size() - 1;
        int col = grid[0].size() - 1;
	/*Approach: As we are given sorted matrix (row and column wise), that means it is more optimized
 	if we start scanning from the bottom right corner of the matrix. Once we find out a non-negative number
 	we immediately stop scanning the matrix, and return count.*/
        
        for(int i = row; i >= 0; i--){
            for(int j = col; j >= 0; j--){
                if(grid[i][j] >= 0) break;
                count++;
            }
        }
        return count;
         
    }
};
    
