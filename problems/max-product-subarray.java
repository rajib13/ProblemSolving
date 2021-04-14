class Solution {
    public int maxProduct(int[] nums) {
        int globalMax = nums[0];
        int localMax = nums[0];
        int localMin = nums[0];
        
        for(int i = 1; i < nums.length; i++){
            int maxProduct = localMax * nums[i];
            int minProduct = localMin * nums[i];
            
            localMax = Math.max(maxProduct, nums[i]);
            localMax = Math.max(minProduct, localMax);
            
            localMin = Math.min(maxProduct, nums[i]);
            localMin = Math.min(minProduct, localMin);
            
            globalMax = Math.max(globalMax, localMax); 
        }
        return globalMax; 
        
    }
}

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given `nums`, as we need to scan every element once.
    Space: O(1), since we do not use any extra space.
*/
