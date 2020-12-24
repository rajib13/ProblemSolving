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
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->val == 0 and root->left == NULL and root->right == NULL) return NULL;
        
        return root; 
    }
};

/*
    Complexity analysis:
    Time: O(n), where n is the total number of nodes in the given tree, as we need to scan all nodes once.
    Space: O(h), where h is the height of the tree- the size of the implicit call stack of recursion.
*/
