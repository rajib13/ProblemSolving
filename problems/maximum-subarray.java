class Solution {
    public int maxSubArray(int[] nums) {
        int best = 0;
        int maxx = 0;
        for(int num : nums){
            maxx = Math.max(maxx + num, num);
            best = Math.max(best, maxx);
        }
        return best;
    }
}
