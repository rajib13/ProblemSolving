class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        /*First, inverse the given matrix changing the row into column and vice versa.*/
        for(int i = 0 ; i < row; i++){
            for(int j = 0; j < i; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }     
        /*Now swap the frist column with last column and so on so forth. */
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col/2; j++){
                swap(mat[i][j], mat[i][col - 1 - j]);
            }
        }
    }
};

/*
    Complexity analysis:
    Time: O(m*n), where `m` and `n` are the  number of rows and cols of the given matrix, as we need scan every element of the `mat` at least once.
    Space: o(1), since we do not use any auxiliary space.
*/
