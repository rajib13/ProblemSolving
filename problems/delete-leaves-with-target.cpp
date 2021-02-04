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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == NULL) return NULL;
        
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        
        if(root->val == target and root->left == NULL and root->right == NULL) return NULL;
        
        return root;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the number of nodes in the given tree.
    Space: O(h), where `h` is the height of the tree that will be in the stack call space, in worst case (left or right skewed tree) the height could be O(n).  
*/
