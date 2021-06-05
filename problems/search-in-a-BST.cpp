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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
            if(root->val == val) break;
            else if(root->val > val) root = root->left;
            else root = root->right;
        }
        return root;
    }
};

/*
    Complexity analysis:
    Time: O(h), where `h` is the height of the given tree, as in iteration we will discard half of the nodes.
    Space:(1), since we do not use any extra space.
*/
