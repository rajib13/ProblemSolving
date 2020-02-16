class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int count = 0;
        int row = grid.size() - 1;
        int col = grid[0].size() - 1;
        
        for(int i = row; i >= 0; i--){
            for(int j = col; j >= 0; j--){
                if(grid[i][j] >= 0) break;
                count++;
            }
        }
        return count;
        
    }
};
