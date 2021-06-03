class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i-1];
        }
        return nums;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the size of the given nums, as we need to scan all elemlents once.
    Space: o(1), since we do not use any auxiliary space.
*/
