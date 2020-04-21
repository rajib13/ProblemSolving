/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        /*O(r+c) approach, where r and c are the row and column respectively.*/
        vector<int> dimension = binaryMatrix.dimensions();
        int row = dimension[0]-1;
        int col = dimension[1]-1;
        
        int r = 0;
        int c = col;
        int leftMost = INT_MAX;
        while(r <= row and c >= 0){
            if(binaryMatrix.get(r,c) == 1){
                leftMost = min(leftMost, c);
                c--;
                
            }
            else{
                r++;
            }
        }
        
        return leftMost == INT_MAX ? -1 : leftMost;
        
    }
};


/*

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        // O(r log(c)) approach, where r and c are the row and column respectively.
        vector<int> dimension = binaryMatrix.dimensions();
        int row = dimension[0];
        int col = dimension[1];

        int leftMost = INT_MAX;
        for(int i = 0; i < row; i++){
            int lowCol = 0; 
            int highCol = col;
            while(lowCol < highCol){
                int midCol = lowCol + (highCol-lowCol)/2;
                if( binaryMatrix.get(i, midCol) > 0) {
                    leftMost = min(leftMost, midCol);
                    highCol = midCol;
                }
                else{
                    lowCol = midCol + 1;
                }
            }
        }
        
        return leftMost == INT_MAX ? -1 : leftMost;
        
    }
};


*/
/*
[
[1,1,1,1,1],
[0,0,0,1,1],
[0,0,1,1,1],
[0,0,0,0,1],
[0,0,0,0,0]]

*/
