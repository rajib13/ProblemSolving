class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while(low < high){
            int mid = low + (high - low)/2;
            if(nums[mid] > nums[high]) low = mid + 1;
            else high = mid;
        }
        
        return nums[low];
    }
};

/*
    Complexity Analysis:
    Time: O(log n), where n is the number of elements in the givn array.
    Space: O(1), since we did  not any extra space.
*/
