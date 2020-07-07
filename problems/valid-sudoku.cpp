class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_set<string> set;
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                string row = to_string(board[i][j]) + " in row " + to_string(i);
                string col = to_string(board[i][j]) + " in cool " + to_string(j);
                string smallSquare = to_string(board[i][j]) + " in smallSquare " + to_string(((i/3) * 3) + j/3);
                
                if(!set.insert(row).second ||
                   !set.insert(col).second ||
                   !set.insert(smallSquare).second ) return false;
            }
        }
        return true;
    }
};
