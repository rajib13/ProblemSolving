class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int maxx = INT_MIN;
        vector<int> ret;
        for(int i = heights.size() - 1; i >= 0; i--){
            if(heights[i] > maxx){
                ret.push_back(i);
                maxx = heights[i];
            }
        } 
        int n = ret.size();
        for(int i = 0; i < n/2; i++){
            swap(ret[i], ret[n - i - 1]);
        }
    
        return ret;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given heights
    Space: O(1), since we do not use any extra space.
*/
