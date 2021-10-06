class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++) {
            int val = abs(nums[i]) - 1;
            if(nums[val] > 0)
                nums[val] *= -1;
            else
                ret.push_back(val + 1);
        }
        return ret;
        
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given array, as we need to scan every element.
    Space: O(1), since we do not use any extra space. 
*/
