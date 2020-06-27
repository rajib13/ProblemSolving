class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int pointer1 = 0;
        int pointer2 = nums.size() - 1;
        
        for (int i = 0; i<nums.size(); i++){
            if(nums[pointer1] + nums[pointer2] == target){
                return {pointer1+1, pointer2+1};
            }
            else if(nums[pointer1] + nums[pointer2] > target){
                pointer2--;
            }
            else{
                pointer1++;
            }
        }
        return {pointer1+1, pointer2+1}; 
        
    }
};

/*
Complexity analysis:
Time: O(n), where n is the number of elements in the given array.
Space: O(1), since we did not use any extra space.
*/
