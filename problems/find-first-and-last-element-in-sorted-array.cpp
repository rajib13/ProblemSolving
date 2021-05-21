class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret{-1, -1};
        int startTarget = binSearch(nums, target, true);
        if(startTarget == nums.size() || nums[startTarget] != target){
            return ret;
        }
        else{
            ret[0] = startTarget;
            ret[1] = binSearch(nums, target, false) - 1;
        }
        return ret;
    }
    
    int binSearch(vector<int>& nums, int target, bool left){
        int low = 0; 
        int high = nums.size();
        
        while(low < high){
            int mid = low + (high - low)/2;
            if(nums[mid] > target || (left && nums[mid] == target)){
                high = mid;
            }  else  low = mid + 1;
        }
        return low;
    }
};

/*
    Complexity analysis:
    Time: O(logn), where `n` is the number of elements in the nums. 
    Space: O(1), since we do not use any extra space. 
*/
