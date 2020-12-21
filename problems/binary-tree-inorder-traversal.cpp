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
    vector<int> inorderTraversal(TreeNode* root) {
        
        /***************** Iterative solution *************/
      
        vector<int> inorder;
        stack<TreeNode*> nodes;
        
         if(root == NULL) return inorder; 
        
        while(root != NULL || !nodes.empty()){
            
            while(root != NULL){ 
                //push left children if available
                nodes.push(root);
                root = root->left;
            }
            //retrieve top node and store its right child if exists
            root = nodes.top();
            nodes.pop();
            
            inorder.push_back(root->val);
            root = root->right;
        }
        return inorder;
        
    }
};
/* Approach 2: recursive
    vector<int> inorder;
    vector<int> inorderTraversal(TreeNode* root) {
    
        if(root == NULL) return inorder;
        
        if(root->left)  inorderTraversal(root->left);
        inorder.push_back(root->val);
        if(root->right) inorderTraversal(root->right); 
        
        return inorder;
    }
    
*/

/*
    Complexity analysis:
    Time: 0(n), as we need to traverse the whole given tree of `n` nodes.
    Space: O(n), since we need to store the `height of the tree` into the stack. In the worst case, (left or right skewed tree) the height could be of all `n` nodes;
*/
