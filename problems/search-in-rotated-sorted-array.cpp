class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low = 0;
        int high = nums.size() - 1; 
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(nums[mid] == target) return mid;
            else if(nums[mid] >= nums[low]){ // left side is sorted
                if(target >= nums[low] and target < nums[mid]) high = mid - 1; // target is in the left side
                else low = mid + 1; // target is in the right side
            }
            else{ // right side is sorted
                if(target > nums[mid] and target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }
};

/*
    Complexity analysis:
    Time: O(log n), as at every iteration we removed half of the elements.
    Space: O(1), since throughout the entire program we did not use any extra space.
*/
