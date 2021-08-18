/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;
    int goodNodes(TreeNode* root, int maxx = INT_MIN) {
        if(root == nullptr) return 0;
        if(root->val >= maxx) {
            count++;
            maxx = root->val;
        }
        int left = goodNodes(root->left, maxx);
        int right = goodNodes(root->right, maxx);
        
        return count;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the number of nodes of the given tree, as we need to scan every node of the tree.
    Space: O(n), in worst case, if the given tree is left or skewed tree then we need to store all `n` nodes in the recursion call    stack.
*/
