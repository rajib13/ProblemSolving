class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        vector<vector<int>> dia;
        int row = mat.size();
        int col = mat[0].size();
        // Idea: Find all diagonals, sort them and store them in a 2d vector diagonal (dia). 
        // Total number of diagonals would be (row + col - 1), also same the diagonals row size. 
        
        if(row == 1 or col == 1) return mat;
        
        vector<int> d; 
        
        // First, find all diagonals of lower sub matrix [0, row -1]
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
               if(c + r < row) d.push_back(mat[c+r][c]);
            }
            sort(d.begin(), d.end());
            dia.push_back(d);
            d.clear();
        }
        // Now, find all diagonals of upper sub matrix diagonal size (dia[row, row + col -1])
        for(int c = 1; c < col; c++){
            for(int r = 0; r < row; r++){
                 if(c+r < col) d.push_back(mat[r][c+r]);
            }
            sort(d.begin(), d.end());
            dia.push_back(d);
            d.clear();
        }
        /*
       for(int i = 0; i < dia.size(); i++){
            for(int j = 0; j < dia[i].size(); j++){
                cout << dia[i][j] << " ";
            }
            cout << endl;
        }
        */
        // Update the lower sub matrix with the value of dia. 
        for(int r = 0; r < row; r++){
            int j = 0;
            for(int c = 0; c < col; c++){
                if(c + r < row) mat[c+r][c] = dia[r][j++];
            }
        }
        
        // Finally, update the upper submatrix. 
        int r1 = row; // because upper sub-matrix starts from row-th position of dia. 
        for(int c = 1; c < col; c++){
            int j = 0; 
            for(int r = 0; r < row; r++){
                 if(c+r < col) mat[r][c+r] =  dia[r1][j++];
            }
            r1++;
        }
        
    return mat;
        
    }
};

/*
[[1,2,3,4,5]]
[[1],[2],[3],[4]]
[[1]]
[[1,2,3,4],[5,6,7,8]]
[[3,3,1,1],[2,2,1,2],[1,1,1,2]]
*/
