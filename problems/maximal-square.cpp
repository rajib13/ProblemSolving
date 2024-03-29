class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        
        int largestSize = 0;
        int count = 0; 
        for(int i = 0; i < matrix.size(); i++)    // Checking is there any 1 in the first column. 
            if(matrix[i][0] == '1') count++;
        for(int i = 0; i < matrix[0].size(); i++) // Checking is there any 1 in the first row. 
            if(matrix[0][i] == '1') count++;
        if(count > 0) largestSize = 1; // If there is a 1 anywhere in the first row or column then the minimum square size would be 1. 
        
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j] == '1'){ // General case. 
                    
                    int topLeft = matrix[i-1][j-1]-'0';
                    int left = matrix[i][j-1]-'0';
                    int top =  matrix[i-1][j]-'0';
                    
                    int size =  1 +  min(topLeft, min(top, left));
                    largestSize = max(largestSize, size);
                    matrix[i][j] = size + '0'; // as we are dealing with the char matrix and need to insert back. 
                    
                }
            }
        }
        return largestSize * largestSize;
    }
};

/*
    Time: O(MN), as we need to scan all elements at least once, where M and N are the row and column respectively. 
    Space: O(mn), as we modify the given matrix 
*/
