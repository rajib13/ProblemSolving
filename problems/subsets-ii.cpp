class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, ret, curr);
        
        return ret;
    }
    
private: 
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& ret, vector<int>& curr){
        ret.push_back(curr);
        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            backtrack(nums, i + 1, ret, curr);
            curr.pop_back();
        }
    }
};

/*
    Complexity analysis:
    Time: O(n.2^n), where `n` is the number of nodes in the given list, as the total number of recursive function call 2^n times for all n elements.
    Space: O(n), recursion call stack occupies at most O(n) space. 
*/
