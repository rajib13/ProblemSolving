class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int t) {
        
        int row = mat.size();
        if(row == 0) return 0; 
        int col = mat[0].size();
        
        vector<vector<int>> dp (row+1, vector<int> (col+1, 0));
        
        int minSide = INT_MAX;
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
        
        int sideLength = 0;
        
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                 int limit = min(i,j); // Because we need to count only square matrix.  
                 for(int k = 0; k <= limit; k++){

                    int area = dp[i][j] - dp[i][j-k] - dp[i-k][j] + dp[i-k][j-k];
                    
                    if(area <= t){
                        sideLength = max(sideLength, k);
                    }
            }
        }
    }
  
        return sideLength; 
    }
};

/*
[[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]]
4
[[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]]
1
[[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]]
6
[[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]]
40184
[[1,3,3,2,2,7,6],[23,354,54,545,452,232,2],[1,1,1,1,1,1,2323],[2,2,2,2,2,2,2],[42,12,23,43,54,45,45],[23,2,32,232,2,2,2]]
2333
[[1,3,3,2,2,7,6],[23,354,54,545,452,232,2],[1,1,1,1,1,1,2323],[2,2,2,2,2,2,2],[42,12,23,43,54,45,45],[23,2,32,232,2,2,2]]
23
[[1,2,3,4,3,6,6,7]]
5
[[1,2,3,4,3,6,6,7]]
0

*/
