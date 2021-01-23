class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ret;
        for(int i = 0; i < nums.size(); i += 2){
            ret.insert(ret.end(), nums[i], nums[i+1]);
        }
        return ret;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given nums, as we need to scan all elements.
    Space: O(1), since we do not use any auxilary space;
*/
