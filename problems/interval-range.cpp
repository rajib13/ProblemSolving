class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ranges, vector<int>& newInterval) {
        
        int start = newInterval[0];
        int end = newInterval[1];
        vector<vector<int>> result;
        int i = 0;
        int sz = ranges.size();
        while(i < sz and ranges[i][1] < start) result.push_back(ranges[i++]);
        while(i < sz and ranges[i][0] <= end){
            start = min(ranges[i][0], start);
            end = max(ranges[i][1], end);
            i++;
        }
        result.push_back({start, end});
        while(i < sz and ranges[i][0] > end) result.push_back(ranges[i++]);
        
        return result;
    }
};

/*
    Complexity analysis:
    Time : O(n), as we need to scan every range in the ranges.
    Space: O(1), as we do not use any extra space.
*/
