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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL or q == NULL ) return p == q;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
 
/*
    Complexity analysis:
    Time: O(n), where `n` is the number of nodes in the given tree, as we need to check the both trees once.
    Space: o(n), since in worst case (left or right skewed tree) the recursion stack will hold up `n` nodes.
*/
