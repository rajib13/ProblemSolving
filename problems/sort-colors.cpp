class Solution {
public:
    void sortColors(vector<int>& nums) {
        int redPointer = 0; 
        int bluePointer = nums.size() - 1; 
        
        for(int i = 0; i <= bluePointer; i++){
            if(nums[i] == 0){
                swap(nums[redPointer++], nums[i]);
            }
            else if(nums[i] == 2){
                swap(nums[bluePointer--], nums[i--]);
                
            }
        }
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given array, as we need to scan every character of the string once.
    Space: O(1), since we do not use any additional space. 
*/
