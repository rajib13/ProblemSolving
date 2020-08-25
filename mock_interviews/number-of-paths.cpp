int numOfPathsToDest( int n ) 
{
  if(n < 3) return 1; 
  vector<vector<int>> dp(n, vector<int>(n, 0)); 
  // The highest possible ways for one row is 1
  for(int i = 0; i < n; i++)
    dp[n-1][i] = 1;
  
  for(int i = n - 2; i >= 0; i--){ 
    for(int j = n - i - 1; j < n; j++){ 
      dp[i][j] += (dp[i][j-1] + dp[i+1][j]);
    }
  }
  
  return dp[0][n-1];
}

/*
Complexity analysis:
Time: O(n^2), where n is the row or col of the given square matrix.
Space: O(n^2), since we used a 2D vector to store the number of paths for all subproblems.
*/
