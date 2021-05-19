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
    Complexity analysis:
    Time: O(n), where `n` is the number of nodes in the given tree, as we need to traverse the entire tree once.
    Space: O(n), since we use the recursion approach, there will stack space, in the worst case (left or right skewed tree) the stack will hold `n` nodes.
*/
