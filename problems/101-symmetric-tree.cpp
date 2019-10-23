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
        TreeNode* root1 = root;
        
        while(!nodes.empty() or root != NULL){
            while(root != NULL){
                nodes.push(root);
                if(root1 == NULL) return false; 
                nodes.push(root1);
                
                root = root->left;
                root1 = root1->right;
            }
            root = nodes.top(); nodes.pop();
            root1 = nodes.top(); nodes.pop();
            
            if(root->val != root1->val) return false;
            root = root->right;
            root1 = root1->left;
        }
        
        return true; 
    }
};
