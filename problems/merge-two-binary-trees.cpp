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
        if(t1 == NULL) return t2; // if one of them are null then no need to merge, just return the other tree.
        if(t2 == NULL) return t1;
        t1->val += t2->val;

        t1->left = mergeTrees(t1->left, t2->left); 
        t1->right = mergeTrees(t1->right, t2->right);

        return t1;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the minimum number of nodes of either tree, as we need to scan every node of the tree which has less nodes.
    Space: O(n), in worst case (left or right skewed binary tree) the recursive call stack will hold `n` nodes.
*/
