class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given array, as the unique function internaly scans all elements once.
    Space: O(1), since we do not use any extra space.

*/
