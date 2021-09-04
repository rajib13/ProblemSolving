class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0];
        int maxx = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            maxx = max(maxx + nums[i], nums[i]);
            best = max(maxx, best);
        }
        return best;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the number of elements in the given array, as we need to scan all elements once.
    Space: O(1), since we do not use any extra space.
*/
