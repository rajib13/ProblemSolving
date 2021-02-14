class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0; 
        for(int num : nums){
            if(int(log10(num)) % 2 != 0) count++;
        }
        return count; 
    }
};

/*
    Complexity analysis:
    Time: O(logn), where `n` is the length of the given nums array.
    Space: O(1), since we do not use any extra space.
*/
