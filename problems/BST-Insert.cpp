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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root == NULL) return new TreeNode(val); // If the root is empty the given value should be the root. 
    
        TreeNode* head = root;
        while(root){
            if(val < root->val){
                if(root->left == NULL){
                    root->left =  new TreeNode(val); break;
                } else root =  root->left;
            }
            else{
                if(root->right == NULL){
                    root->right =  new TreeNode(val); break;
                } else root =  root->right;
            }
        }
        return head;
    }
};
