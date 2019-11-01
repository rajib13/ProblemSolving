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
        
        vector<int> preorder;
        vector<int> preorderTraversal(TreeNode* root) {
    
        if(root == NULL) return preorder;
        
        preorder.push_back(root->val);
        if(root->left)  preorderTraversal(root->left);
        if(root->right) preorderTraversal(root->right); 
        
        
        return preorder;
        
    }
};
