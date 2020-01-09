class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        
        int row = board.size();
        int col = board[0].size();
        
        int count = 0;
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                
                if(board[r][c] == 'X'){
                    // First row and first column of every row is about to start a new count, and in general 
                    // if and only if in previous row same column and previous coulumn of same row have not X. 
                    if((r == 0 or board[r-1][c] != 'X') and (c == 0 or board[r][c-1] != 'X')) count++; 
                }
            }
        }
        return count;
        
    }
};

/*
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        // Approach 1 : with flag variable.
        int row = board.size();
        int col = board[0].size();
        
        int count = 0;
        for(int i = 0; i < row; i++){
            bool flag = true;
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'X'){
                    if((i == 0 and flag == true) or (i > 0 and flag == true and board[i-1][j] != 'X')) {
                        count++;
                        flag = false;
                    }
                }
                else flag = true;
            }
        }
        return count;
        
    }
};
*/
