class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == i % 10) return i;
        }
        return -1;
    }
};


/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the `nums` array, as we need to scan every element.
    Space: O(1), since we do not use any extra space. 
*/
