class Solution {
public:
    int uniquePaths(int row, int col) {
        vector<int> dp(col, 1);
        // Approach 2: Just add the previous column value to the current one is enough to get the solution
        for(int r = 1; r < row; r++){
            for(int c = 1; c < col; c++){
                dp[c] += dp[c-1];
            }
        }
        
        return dp[col-1];
    }
};
/*
    Complexity analysis: 
    Time: O(m*n), where `m` and `n` are the given number of rows and cols, respectively, 
          as we need to scan every element in the grid making by row and col.
    Space: O(n), since we use an auxiliary space to store the intemediate results. 
*/
