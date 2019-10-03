class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int row = mat.size();
        if(row == 0) return false;
        int col = mat[0].size();
        if(col == 0) return false;
        
        for(int i=0; i<row; i++){
            if(target >= mat[i][0] && target <=mat[i][col-1]){
                row = i;
            }   
        }
        if(row == mat.size()) return false;
        for(int i=0; i<col; i++){
            if(mat[row][i] == target){
                return true;
            
            }
        }
        return false; 
        
    }
};
