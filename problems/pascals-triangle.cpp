class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        if(numRows == 0) return ret;
        
        ret[0].push_back(1);
        
        for(int i = 1; i < numRows; i++){
            int backSize = ret[i-1].size(); 
            ret[i].push_back(1); // first one
            for(int j = 0; j  < backSize-1; j++){
                int tmp = ret[i-1][j] + ret[i-1][j+1];
                ret[i].push_back(tmp);
            }
            ret[i].push_back(1); // last one
        }
        return ret;
    } 
};

/*Complexity Analysis: 
Time: O(n^2), where n is the number of the rows.
Space: O(n^2), since we need to send all rows upto the given numRows.
*/
