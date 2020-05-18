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
Time: O(n) as we need to scan all of the nodes
Space: O(log n) for the recursive call stack. 

*/
