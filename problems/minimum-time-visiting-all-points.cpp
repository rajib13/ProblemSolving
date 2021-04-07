class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ret = 0; 
        for(int i = 0; i < points.size() - 1; i++){
            ret += max(abs(points[i][0] - points[i+1][0]), abs(points[i][1] - points[i+1][1]));
        }
        return ret;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the `points`, as we need to scan every point once.
    Space: O(1), since we do not use any extra space.
*/
