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
class Solution {
public:
    int uniquePaths(int row, int col) {
        //Approach 1:  Two rows are enough to produce the result. We generate the second row from the first one.
 
        vector<vector<int>> dp(2, vector<int> (col, 1));
        
        for(int r = 1; r < row; r++){
            for(int c = 1; c < col; c++){
                dp[1][c] = dp[0][c] + dp[1][c-1];
            }
            for(int c = 1; c < col; c++)
                dp[0][c] = dp[1][c];
        }
        
        return dp[1][col-1];
        
    }
};
*/
