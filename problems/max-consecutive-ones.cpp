class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0; 
        int maxx = 0;
        for(int num : nums){
            if(num == 1) {
                count++;
                maxx = max(maxx, count);
            }
            else count = 0;
        }
        return maxx; 
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given nums, as we need to scan every element of the nums.
    Space: O(1), since we do not use any extra space.
*/
