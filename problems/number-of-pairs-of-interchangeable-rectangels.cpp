class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> map;
        long long count = 0;
        for(auto rectangle : rectangles){
            double ratio = (double) rectangle[0]/rectangle[1];
            if(map.find(ratio) != map.end()) count += map[ratio];
            map[ratio]++;
        }
        return count;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of then rectangels, as we need to find out the width to height ratio of all rectangles.
    Space: O(n), since we store the ratio in a hashmap.
*/
