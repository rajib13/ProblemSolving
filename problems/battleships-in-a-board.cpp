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
    Complexity analysis:
    Time: O(mn), where m and n are the row and column of the given board.
    Space: O(1), since we do not use any extra space throughout the entire program.
*/
