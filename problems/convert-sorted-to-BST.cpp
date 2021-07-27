/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size() - 1;
        return dfs(nums, 0, n);
    }
    
private:
    TreeNode* dfs(vector<int>& nums, int start, int end){
        if(start > end) return nullptr;
        
        int mid = start + (end - start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = dfs(nums, start, mid - 1);
        root->right = dfs(nums, mid + 1, end);
        
        return root;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the number of elements in the given nums, since we need to create BST node for every element.
    Space: O(logn), for the recursion call stack space. 
*/
