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
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> nodes;
        TreeNode* root1 = root; // For traversing the right side of the tree.
        
        while(!nodes.empty() or root != NULL){
            while(root != NULL){
                nodes.push(root);
                if(root1 == NULL) return false; // In a assymmetric tree, right side could not be invalid. 
                nodes.push(root1);
                
                root = root->left; // We are traversing from the root to leftmost node.
                root1 = root1->right; // Another pointer to traverse from the root to rightmost node.
            }
            root = nodes.top(); nodes.pop(); 
            root1 = nodes.top(); nodes.pop();
            
            if(root->val != root1->val) return false; // In a symmetric tree, every two entries of stack should be same. 
            root = root->right;
            root1 = root1->left;
        }
        return true; 
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the number of nodes in the given tree, as we need to iterate through the entire tree once.
    Space: O(n), in worst case (left or right skewed tree), we need to stroe `n` nodes in the recursion call stack.
*/
