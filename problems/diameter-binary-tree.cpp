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
    int maxx = 0;
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right); 
        maxx = max(maxx, left + right);
        return max(left, right) + 1; 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == nullptr) return 0;
        dfs(root);
        
        return maxx;
        
    }
};

/*
    Complexity:
    Time: O(n), where n is the node number in the given tree.
    Space: O(log n), the stack space.
*/
