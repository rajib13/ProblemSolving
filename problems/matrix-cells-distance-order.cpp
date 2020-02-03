class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r, int c) {
        vector<vector<int>> seen(R, vector<int>(C, 0)); 
        vector<vector<int>> ret;
        queue<pair<int, int>> q;
        // Initialize the queue with given position. 
        q.push({r,c});
        seen[r][c] = 1;
        
        while(!q.empty()){
            pair<int, int> pos = q.front(); q.pop();
            int row = pos.first;
            int col = pos.second;
            ret.push_back({row, col});
            
            
            int down = row + 1;
            int up = row - 1;
            int left = col - 1;
            int right = col + 1; 
            
            // Find the valid cell, push to the queue and also mark the cell as seen.
            if(down < R and seen[down][col] == 0) {q.push({down, col}); seen[down][col] = 1;}
            if(up >= 0 and seen[up][col] == 0) {q.push({up, col}); seen[up][col] = 1;}
            if(right < C and seen[row][right] == 0) {q.push({row, right}); seen[row][right] = 1;}
            if(left >= 0 and seen[row][left] == 0) {q.push({row, left}); seen[row][left] = 1;}
        }
        
        return ret;
        
    }
};
