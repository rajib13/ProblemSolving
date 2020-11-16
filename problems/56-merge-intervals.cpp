class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> overlap;
    
        if(intervals.size() == 0) return overlap;
        
        sort(intervals.begin(), intervals.end());
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            
            if(end< intervals[i][0]){
                overlap.push_back({start, end});
                    start = intervals[i][0];
            }
            end = max(end, intervals[i][1]);
        }
        overlap.push_back({start, end});
        return overlap;
    }
};
/*
    Complexity analysis: 
    Time: O(nlogn), where n is the number of the given intervals.
    Space: O(1), since we did not use any extra space.
*/
