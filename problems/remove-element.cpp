class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int elementCount = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[elementCount++] = nums[i];
            }
        }
        return elementCount; 
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is length of the given nums, as we need to scan every number. 
    Space: O(1), since we do not use any extra space. 
*/ 
