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
        if(root == nullptr) return total;
        
        sum = sum * 10 + root->val;
        if(!root->left and !root->right) total += sum; 
        sumNumbers(root->left, sum);
        sumNumbers(root->right, sum);
    
        return total; 
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the number of nodes in the given tree, as we need to iterate through the entire tree once.
    Space: O(n), in worst case (left or right skewed tree), we need to stroe `n` nodes in the recursion call stack.
*/
