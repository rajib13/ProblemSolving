class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0; 
        for(int num : nums){
            if(count < 2 || num > nums[count-2]) nums[count++] = num;
        }
        return count;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given nums, as we need scan every element of the nums once.
    Space: o(1), since we used only a vector of size 26.
*/
