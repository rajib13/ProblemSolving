class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i >= grid.size() or i < 0 or j >= grid[0].size() or j < 0 or grid[i][j] != '1') return;
        grid[i][j] = '0';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        
    }
    int numIslands(vector<vector<char>>& grid) {
      
        int count = 0; 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};

/*
    Complexity Analysis:
    Time: O(mn), where `m` and `n` are the given grid size, as we need to scan all array elements once.
    Space: O(mn), since we recursively call the `dfs` function. 
*/
