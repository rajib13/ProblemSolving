class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int e) {
        vector<bool> ret;
        int maxx = 0; 
        
        for(int can : candies){
            maxx = max(maxx, can);
        }
        
        for(int can : candies){
            if(can + e >= maxx) ret.push_back(true);
            else ret.push_back(false);
        }
        
        return ret;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the number of candies.
    Space: O(1), as we did not use any extra space.
*/
