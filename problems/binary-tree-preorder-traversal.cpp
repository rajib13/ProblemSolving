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
                //push the root node
                nodes.push(root);
                root = root->left; /*** Left ***/
            }
            
            //retrieve top node and store its right child if exists
            root = nodes.top(); nodes.pop();
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
    Complexity analysis:
    Time: O(n), since we need to scan all nodes once.
    Space: O(n), as in worst case (left or right skewed tree) we may need to store all n nodes into the stack.
*/
