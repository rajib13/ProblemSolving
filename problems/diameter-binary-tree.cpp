/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/
class Solution {
public:
    int ans = INT_MIN;
    int maxx = 0;
    int helper(TreeNode* root){
        if(root == nullptr) return 0;
        int left = helper(root->left);
        int right = helper(root->right); 
        maxx = max(maxx, left + right);
        return max(left, right) + 1; 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == nullptr) return 0;
        helper(root);
        
        return maxx;
        
    }
};
