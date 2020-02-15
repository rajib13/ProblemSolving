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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) return NULL;
        
        root->left = pruneTree(root->left); // recursively call the left sub-tree.
        root->right = pruneTree(root->right); // recursively call the right sub-tree.
        
        if(root->val == 0 and root->left == NULL and root->right == NULL) return NULL;
        
        return root;
        
    }
};
