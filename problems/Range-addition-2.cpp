class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minRow = m;
        int minCol = n;
        
        for(auto op : ops){
            minRow = min(minRow, op[0]);
            minCol = min(minCol, op[1]);
        }
        
        return minRow * minCol;
    }
};

/*
    Complexity analysis:
    Time: O(x), where `x` is the number of operations, as we need to iterate over every operation.
    Space: O(1), since we do not use any extra space.
*/
