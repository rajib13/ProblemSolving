class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        /*Approach 1: binary search by pair. The solution will always be in even-index position.*/
        int low = 0;
        int high = nums.size()/ 2;
        
        while(low < high){
            int mid = low + (high - low)/2;
            if(nums[2*mid] != nums[2*mid  + 1]) high = mid;
            else low = mid + 1;
        }
        return nums[2 * low];
        
    }
};



/*

First Solution: Polished version.

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int low = 0;
        int high = nums.size() - 1;
        
        while(low < high){
            int mid = low + (high - low)/2;
            if(mid == 0) return nums[mid]; // crucial, because if mid == 0, then in the next line nums[mid - 1] is invalid.
            
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1] ) return nums[mid]; // Base case, we found the solution as the nums is sorted.
            
            else if( mid % 2 == 0 and  nums[mid] == nums[mid + 1]){ // Condition to get the single number in the right side.  
                    low = mid + 1;
                }
            
            else if( mid % 2 != 0 and nums[mid] == nums[mid - 1]){ // symmetric condition to get the single number in the right side.
                    low = mid + 1;
                }
            else{
                    high = mid - 1; // Otherwise: single number is in the left side.
                }
        }
        return nums[low];
        
    }
};

*/

/*Test Cases

[1,1,2,3,3,4,4,8,8]
[3,3,7,7,10,11,11]
[1,2,2,3,3]
[1,1,2,2,3]
[1,1,2]
[1,2,2]


*/
