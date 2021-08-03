class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int n = nums.length;
        int closest = 100000;
        Arrays.sort(nums);
        
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int j = i + 1;
            int k = n - 1;
            
            while(j < k){
                int tmp = nums[i] + nums[j] + nums[k];
                
                if(Math.abs(tmp - target) < Math.abs(closest - target)){
                    closest = tmp;
                }
                if(tmp > target) k--;
                else j++;
            }
        }
        return closest;
    }
}

/*
    Complexity analysis:
    Time: O(n^2), where `n` is the number of elements in the given array, as we have outer and inner loops, and each going through n elements.
    Space: O(logn) to O(n), depending on the implementation of the sorting alroithm.
*/
