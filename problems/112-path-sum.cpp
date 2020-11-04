/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    /*Approach 2 : recursion */
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        if(root->val == sum and root->left == NULL and root->right == NULL) return true;
        return hasPathSum(root->left, sum - root->val) or hasPathSum(root->right, sum - root->val);
        
    }
};

/*
    Complexity analysis: 
    Time: O(n), in worst case we need to scan all nodes once.
    Space: O(logn), for the recursion stack space.
*/

