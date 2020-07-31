int deletionDistance( const string& str1, const string& str2 ) 
{
    int row = str1.size();
    int col = str2.size();
    
    vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
  
    for(int i = 0; i <= row; i++){
      for(int j = 0; j <= col; j++){
        
            if(i == 0) dp[i][j] = j; // first row where word1 is empty
        
            else if(j == 0) dp[i][j] = i; // first column where word2 is empty
        
            else if(str1[i-1] == str2[j-1])
              dp[i][j] = dp[i-1][j-1];
        
            else dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
          }
      }
  
    for(int i = 0; i <= row; i++){
      for(int j = 0; j <= col; j++){
        cout << dp[i][j] << " ";
      }
      cout << endl; 
    }
   return dp[row][col];
}

/*Complexity Analysis: 
Time : O(mn), where m is the str1 and n is the str2 size.
Space: O(mn), since we used a dp vector to store the intermediate results.
*/
