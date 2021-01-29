class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        float m1 = 0; 
        float m2 = 0; 
        
        for(int i = 0; i < coordinates.size() - 1; i++){
            m2 = coordinates[i+1][0] - coordinates[i][0] == 0 ? 0 : (float)(coordinates[i+1][1] - coordinates[i][1])/(float)(coordinates[i+1][0] - coordinates[i][0]);
            if(i > 0 and m1 != m2) return false;
            m1 = m2; 
               
        }
        return true;
    }
};

/*
    Complexity Analysis:
    Time: O(n), where n is the size of the given cordinates, as we need to scan every coordinate;
    Space: O(1), since we did not use any extra space;
*/
