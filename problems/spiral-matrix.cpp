class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int lastRow = matrix.size();
        if(lastRow == 0) return ret;
        int lastCol =  matrix[0].size();
        
        int firstRow = 0, firstCol = 0;
        
        while(firstRow < lastRow and firstCol < lastCol){
            for(int i = firstCol; i < lastCol; i++){
                ret.push_back(matrix[firstRow][i]);
            }
            firstRow++;
            
            for(int i = firstRow; i < lastRow; i++){
                ret.push_back(matrix[i][lastCol - 1]);
            }

            lastCol--;
            
            if(lastRow > firstRow){
                for(int i = lastCol - 1; i >= firstCol; i--){
                    ret.push_back(matrix[lastRow - 1][i]);
                }
                lastRow--;
            }
            
            if(lastCol > firstCol){
                for(int i = lastRow - 1; i >= firstRow; i--){
                    ret.push_back(matrix[i][firstCol]);
                }
                firstCol++;
            }
        }
        return ret;
    }
};

/*
    Complexity analysis:
    Time: O(mn), where `m` and `n` are the number of rows and columns in the given matrix, as we need to scan all elements once.
    Space: O(1), since we do not use any extra space.
*/
