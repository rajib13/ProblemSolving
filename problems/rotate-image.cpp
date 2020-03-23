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
