class Solution {
    public int maxSubArray(int[] nums) {
        int best = Integer.MIN_VALUE;
        int maxx = 0;
        for(int i = 0; i < nums.length; i++){
            maxx = Math.max(maxx + nums[i], nums[i]);
            best = Math.max(best, maxx);
        }
        return best;
    }
}

/*
   Complexity analysis:
   Time: O(n), where `n` is the length of the given nums, as we need to scan all elements of the array.
   Space: O(1), since we do not use any extra space.
*/
