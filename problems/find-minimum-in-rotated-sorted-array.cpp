class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1; 
        int minn = INT_MAX;
        
        // Approach 1 : Similar as number 33. Search in rotated sorted array. 
        
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

/**/
