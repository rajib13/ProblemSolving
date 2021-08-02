class Solution {
    public int triangleNumber(int[] nums) {
        int count = 0;
        int n = nums.length;
        Arrays.sort(nums);
        
        for(int i = n-1; i > 1; i--){
            int left = 0; 
            int right = i - 1;
            
            while(left < right) {
                 if(nums[left] + nums[right] > nums[i]){
                     count += (right - left);
                    right--;
                     
                } else left++;
               
            }
        }
        return count;
    }
}

/*
   Complexity analysis:
   Time: O(n^2), where `n` is the length of the given nums, as the inner and outer loops iterate through `n` times.
   Space: O(logn) to O(n), depending on the implementation of the sorting function.
*/
