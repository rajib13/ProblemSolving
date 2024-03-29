class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 or j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};


/*
    Complexity analysis:
    Time: O(m*n), where `m` and `n` are the number of rows and columns of the given grid, respectively.
    Space: O(m*n), since we need to store the unique paths for all possible positions. 
*/
