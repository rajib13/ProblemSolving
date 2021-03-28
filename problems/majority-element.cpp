class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0]; 
        int count = 0;
        for ( int i = 0; i < nums.size(); i++){
            count += nums[i] == majority ? 1 : -1; 
            if(count == 0) majority = nums[i+1];
        }
        return majority;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given `nums`, as we need to scan all elements.
    Space: O(1), since we do not use any extra space.
*/
