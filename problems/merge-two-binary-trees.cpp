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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        
        if(t1 == NULL) return t2; // if one of them are null then no need to merge, just return it.
        if(t2 == NULL) return t1;
        t1->val += t2->val;

        t1->left = mergeTrees(t1->left, t2->left); // Do not need to check whether the left or right exists or not because in the next iteration base case will return it. 
        t1->right = mergeTrees(t1->right, t2->right);

        return t1;
        
    }
};
