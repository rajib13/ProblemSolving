class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single_number = 0;
        for(int i=0; i<nums.size(); i++){
            single_number ^= nums[i]; 
        }
        return single_number;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the lenght of the given nums, as we need to scan all elements once.
    Space: O(1), since we do not use any extra space.
*/
