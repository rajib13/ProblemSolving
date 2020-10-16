class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int> nums, vector<int> temp, int target, int k, int start, int sum){
        if(temp.size() == k and sum == target)
            res.push_back(temp);
        if(temp.size() > k or sum > target)
            return;
        
        for(int i = start; i < nums.size(); i++){
            temp.push_back(nums[i]);
            backtrack(res, nums, temp, target, k, i + 1,  sum + nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> nums{1,2,3,4,5,6,7,8,9};
        
        backtrack(res, nums, temp, n, k, 0, 0);
        return res;
    }
};

/*
Complexity analysis:
Time: O(n!*k/(9-k)!), since we have 1 to 9 possible choices.
Space: O(K), as we need to store k elementes at any given time.
*/
