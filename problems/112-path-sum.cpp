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
Approach 1 : Recursion using helper function.
class Solution {
public:
    bool helper(TreeNode* root, int sum){
        if(root == NULL and sum) return false;
        
        if(root == NULL and sum == 0) return true;
        
        if(root->left and root->right == NULL) return helper(root->left, sum - root->val) ;
        else if(root->right and root->left == NULL) return helper(root->right, sum - root->val);
        else return helper(root->left, sum - root->val) or helper(root->right, sum - root->val);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        return helper(root, sum);
        
    }
};

*/
