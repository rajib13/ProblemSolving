class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int row = mat.size();
        for(int i = 0; i < row; i++){
            sum += mat[i][i] + mat[i][(row-1)-i];
        }
        return row % 2 == 1 ? sum - mat[row/2][row/2] : sum;
    }
};

/*
Complexity analysis:
Time: O(n), where n is the number of rows in the given square matrix.
Space: O(1), since we did  not use any extra space.
*/
