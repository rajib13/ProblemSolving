class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1; 
        int minn = INT_MAX;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            minn = min (minn, nums[mid]); 
            if(nums[mid] < nums[low]){
                high = mid;
            }
            else{
                minn = min(minn, nums[low]); // In case right side is also sorted but with larger value
                low = mid  + 1;
            }
        }
        return minn;
    }
};

/*
    Complexity Analysis:
    Time: O(log n), where n is the number of elements in the givn array.
    Space: O(1), since we did  not any extra space.
*/
