class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 or matrix[0].size() == 0) return false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // First binary search row-wise : Get the row where we can find the target
        int low = 0, high = rows - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(matrix[mid][0] == target) return true;
            else if (matrix[mid][0] < target) low = mid + 1;
            else high = mid - 1;
        }
        if(low == 0) return false;
        int row = low - 1;
        
        // Second binary search colum wise : find the target
        low = 0, high = cols - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};

/*
    Complexity analysis:
    Time: O(log (m + n), where `m` and `n` are the number of elements in the given matrix, as we perform the binary search on row and then on column wise. 
    Space: O(1), since e do not use any extra space.  
*/
