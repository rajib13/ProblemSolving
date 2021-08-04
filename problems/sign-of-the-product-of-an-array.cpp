.class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for(int num : nums){
            if(num == 0) return 0;
            else if(num < 0) sign = -sign;
        }
        return  sign;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given nums, as we need to scan all elements of the array.
    Space: O(1), since we do not use any auxiliary space.
*/
