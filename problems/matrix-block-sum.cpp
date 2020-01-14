class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        
        int row = mat.size();
        int col = mat[0].size();
        
        vector<vector<int>> dp(row+1, vector<int> (col+1, 0));
        vector<vector<int>> ret(row, vector<int> (col, 0));
        
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                /*
                Loop starts with i = 1 and j = 1 so that we can handle the edges (eg mat[0][0], mat[1][0], mat[0][1]) easily.
                and that is why Loop ends with (row+1) and (col+1).
                dp[i][j-1] added all colums value for prefix sum.
                Similarly, dp[i-1][j] added all rows value.
                In that case we actually added dp[i-1][j-1] twice, first in row wise and then in column wise. 
                */
                dp[i][j] = mat[i-1][j-1] + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1]; 
            }
        }
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                
                int r1 = max(i-k, 0) + 1; // dp is 1-indexed but the given matrix and i,j,k are in 0-indexed.
                int c1 = max(j-k, 0) + 1; 
                int r2 = min(i+k, row-1) + 1;
                int c2 = min(j+k, col-1) + 1;
                /*
                1D prefixSum dp[i,j] = dp[0,j] - dp[0,i-1]; Similarly for 2d we need to minus rowwise and columnwise. 
                And as a result we minus dp[i-1][j-1] twice as mentioned above, so we need to add it. 
                Sub PrefixSum (i,j) = Whole PrefixSum (0,j) - columnStart to currentRow -1 (0,i) - rowStart to 
                currentColumn - 1 (0, i) - [i-1][j-1] (as it is added twice).
                */
                ret[i][j] = dp[r2][c2] - dp[r2][c1-1] - dp[r1-1][c2] + dp[r1-1][c1-1];
            }
        }
        return ret;
    }
};
