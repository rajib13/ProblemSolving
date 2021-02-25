class Solution {
public:
    int helper(vector<int>& nums, int start, int numsSize){
        int ptr1 = 0, ptr2 = 0;
        for(int i = start; i < numsSize; i++){
            int curr = max(ptr1 + nums[i], ptr2);
            ptr1 = ptr2;
            ptr2 = curr;
        }
        return ptr2;
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        else if(nums.size() == 1) return nums[0];
        
        return max(helper(nums, 0, nums.size() - 1), helper(nums, 1, nums.size()));
    }
};



/*
    Complexity analysis:
    Time: O(n), where `n` is the lenght of the given nums, as we need to scan the entire nums twice.
    Space: O(1), since  we do not use any extra space.
*/
