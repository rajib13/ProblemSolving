class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int r, int c, int row, int col){
        if(r < 0 or r >= row or c < 0 or c >= col or board[r][c] != word[i]) return false;
        if(i == word.size()-1) return true;
        
        board[r][c] = '0';
        bool searchResult = dfs(board, word, i+1, r+1, c, row, col) || 
                            dfs(board, word, i+1, r, c+1, row, col) ||
                            dfs(board, word, i+1, r-1, c, row, col) ||
                            dfs(board, word, i+1, r, c-1, row, col);
        
        board[r][c] = word[i];  
        
        return searchResult;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int row = board.size();
        int col = board[0].size();
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, 0, i, j, row, col)) return true;
                }
            }
        }
        return false;
    }
};
