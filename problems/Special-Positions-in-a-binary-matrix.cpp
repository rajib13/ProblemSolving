class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        int row = mat.size();
        int col = mat[0].size();
        vector<int> rows(row, 0);
        vector<int> cols(col, 0);
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mat[i][j]){
                    rows[i]++; cols[j]++;
                }
            }
        }
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mat[i][j] and rows[i] == 1 and cols[j] == 1) count++;
            }
        }
        
        return count;
    }
};

/*
    Complexity analysis:
    Time: O(n^2), where n is the row or column size of the given matrix;
    Space: O(n), since we stored the occurances of 1 in any row and column in a vector;
*/
