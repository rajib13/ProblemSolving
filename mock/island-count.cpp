void  dfs( vector<vector<int>>& mat, int r, int c){
  if(r < 0 || c < 0 || r >= mat.size() || c >= mat[0].size() || mat[r][c] != 1) return;
  
  mat[r][c] = 2;
  dfs(mat, r - 1, c); // up
  dfs(mat, r + 1, c); // down
  dfs(mat, r, c + 1); // right
  dfs(mat, r, c - 1); // left
  
}

int getNumberOfIslands( const vector<vector<int>>& binaryMatrix ) 
{
   vector<vector<int>> mat = binaryMatrix;
  
   int row = mat.size();
   int col = mat[0].size();
   int count = 0;
  
   for(int i = 0; i  < row; i++){
     for(int j = 0; j < col; j++){
        if(mat[i][j] == 1){
           dfs(mat, i, j);
           count++;
        }
     }
      
   }
 return count;
}


/*
Comlexity analysis:
Time: O(mn), where m is the row and n is the column of the given matrix.
Space: O(mn), in worst case recursion stack will need to hold all elements, hence the space complexity is also linear.
*/
