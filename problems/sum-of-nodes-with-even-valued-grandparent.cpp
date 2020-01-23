/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0 ; 
        while(!q.empty()){
            
            TreeNode* root = q.front(); q.pop();
            if(root->left){
                q.push(root->left);
            } 

            if(root->right){
                q.push(root->right);
            }
            
            if(root->val % 2 == 0){ 
                if(root->left) {
                    sum += root->left->left != nullptr ? root->left->left->val : 0;
                    sum += root->left->right != nullptr ? root->left->right->val : 0;
                }
                
                if(root->right) {
                    sum += root->right->left != nullptr ? root->right->left->val : 0;
                    sum += root->right->right != nullptr ? root->right->right->val : 0;
                }
                

            }
        }
        return sum;
        
    }
};

*/
class Solution {
public:
    // Approach 2 : Recursive solution
    int sumEvenGrandparent(TreeNode* root, int parent = 1, int grandparent = 1) {
        return root ? sumEvenGrandparent(root->left, root->val, parent) 
                    + sumEvenGrandparent(root->right, root->val, parent)
                    + (grandparent % 2 ? 0 : root->val) //For separating the nested if-else
                    : 0;
    }
};


