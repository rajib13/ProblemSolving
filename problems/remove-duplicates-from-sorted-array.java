class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        if(n == 0) return 0;
        int j = 1;
        
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]) continue;
            nums[j++]= nums[i];
        }
        
        return j;
    }
}

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given array, as the unique function internaly scans all elements once.
    Space: O(1), since we do not use any extra space.
*/
