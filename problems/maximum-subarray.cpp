class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*Approach: Kadene's algorithm*/
        
        int best = nums[0];
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum = max(sum+nums[i], nums[i]);
            best = max(best, sum);
        }
        return best; 
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given `nums`, as we need to scan all elements.
    Space: O(1), since we do not use any extra space.
*/
