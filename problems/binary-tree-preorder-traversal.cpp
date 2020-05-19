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
    vector<int> preorderTraversal(TreeNode* root) {
        
        /***************** Iterative solution *************/
        
        vector <int> preorder; 
        if(root == NULL) return preorder;
        
        stack<TreeNode*> nodes;
        
        while(root != NULL || !nodes.empty()){
            
            while(root != NULL){
                preorder.push_back(root->val); /*** Root ***/
                
                //push left children if available
                nodes.push(root);
                root = root->left; /*** Left ***/
            }
            
            //retrieve top node and store its right child if exists
            root = nodes.top();
            nodes.pop();
            
           
            root = root->right; /*** Right ***/
        }

     return preorder;
        
    }
};


/*
Approach 2: recursive solution
    
    vector<int> preorder;
    vector<int> preorderTraversal(TreeNode* root) {
    
        if(root == NULL) return preorder;
        
        preorder.push_back(root->val);
        if(root->left)  preorderTraversal(root->left);
        if(root->right) preorderTraversal(root->right); 
        
        
        return preorder;
        
    }

*/


/*
    Test Cases: 
    
    [10,5,15,null,null,6,20]
    [5,1,4,null,null,3,6]
    [5,4,6,2,3,null, 9, 1, null, null, null, 8, null, null, null, 7]
    [5, null, 6, null, 7, null, 8]
    [6, 5, null, 4, null, 2 ]
    
*/
