class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret;
        ret.push_back(1);
        
        for(int i = 0; i < nums.size() - 1; i++){
            ret.push_back(ret[i]  * nums[i]);
        }
        
        int prev = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            ret[i] *= prev;
            prev *= nums[i];
        }
        
        return ret;
    }
};

/*
    Complexity analysis
    Time: O(n), whwere `n` is the legth of the given nums, as we scan all elements at least once.
    Space: O(1), as we do not use any extra space.
*/
