class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end());
        ret.push_back(intervals[0]);
        int j = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(ret[j][1] >= intervals[i][0]){
                ret[j][1] = max(ret[j][1], intervals[i][1]);
            } else {
                ret.push_back(intervals[i]);
                j++;
            }
        }
        return ret;
    }
};
/*
    Complexity analysis: 
    Time: O(nlogn), where n is the number of the given intervals.
    Space: O(1), since we did not use any extra space.
*/
