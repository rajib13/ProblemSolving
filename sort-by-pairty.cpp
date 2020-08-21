class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0;
        for(int j = 0; j < nums.size(); j++)
            if(nums[j] % 2 == 0) swap(nums[i++], nums[j]);
        
        return nums;
    }
};

/*
Complexity analysis:
Time: O(n), since we scan all elements of the given array once.
Space: O(1), as we do not use any extra space.
*/
