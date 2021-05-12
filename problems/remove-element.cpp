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
    Time: O(n), where `n` is the number of elements in the nums, as we need to 
    Space: O(1), since we do not use any extra space. 
*/ 
