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
    int total = 0;
    int sumNumbers(TreeNode* root, int sum = 0) {
        sum = sum * 10 + root->val;
        if(root->left == nullptr and root->right == nullptr){
            total += sum;
            return total;
        }

        if(root->left) sumNumbers(root->left, sum);
        if(root->right) sumNumbers(root->right, sum);
        
        return total;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the number of nodes in the given tree, as we need to traverse the entire tree.
    Space: O(h), where `h` is the height of the tree that needs to be stored in the stack space. 
*/
