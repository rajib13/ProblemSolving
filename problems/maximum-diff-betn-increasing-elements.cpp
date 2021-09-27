class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int diff = -1;
        int lowest = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > lowest) {
                diff = max(diff, nums[i] - lowest);
            } else lowest = nums[i];
        }
        return diff;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given nums, as we need to scan all elements once.
    Space: O(1), since we do not use any extra space.
*/
