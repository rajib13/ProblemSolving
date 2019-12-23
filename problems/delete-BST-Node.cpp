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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root) return nullptr;
        
        if(key < root->val) root->left = deleteNode(root->left, key);
        else if(key > root->val) root->right = deleteNode(root->right, key);
        else{
            /*Leaf node case*/
            if(!root->left and !root->right){
                delete(root);
                return nullptr;
            }
            /* Any one child case. Put the child into a temporary variable then delete the root and then return the temporary.*/
            else if(!root->left or !root->right){
                TreeNode* ret = root->left ? root->left : root->right;
                delete(root);
                return ret;
            }
            /*Two childs case. Find out the enext immediate number and that can we find by going one step right and then all the way up to the left.
            Then exchange the value of them. Now again call the deleteNode function, and in that call the node have the key value will be have only 
            right child(s) or none. Then the case can be solved by either of the above two cases. */
            else{
                TreeNode* tmp = root->right;
                while(tmp->left) tmp = tmp->left;
                swap(tmp->val, root->val);
                root->right = deleteNode(root->right, key); 
            }
        }
        return root; 
    }
};

/*
[5,3,6,2,4,null,7]
5
[5,3,6,2,4,null,7]
7
[5,3,6,2,4,null,7]
4
[1,null,2,null,3,null,5]
1
[10,9,null,8,null,7,null,5]
9
[0]
0
[]
9

*/
