/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int ret = 0;
        /***************** Iterative solution *************/
        stack<TreeNode*> nodes;
        
        while(root != NULL || !nodes.empty()){
            bool flag = false;
            while(root != NULL){
                //push left children if available
                nodes.push(root);
                if(!root->left and !root->right and flag) ret += root->val;
                root = root->left;
                flag = true;
            }
            root = nodes.top();
            nodes.pop();

            root = root->right;
        }

     return ret;
    }
};


/*
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool isLeftNode = false) {
        // Approach 2: Recursive Solution
        if(!root) return 0;
        if( !root->left and !root->right and isLeftNode ) return root->val;
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false); 
    }
};
*/


/*
    Complexity analysis:
    Time: O(n), where `n` is the number of nodes in the given tree, as we need to iterate through the entire tree once.
    Space: O(n), in worst case (left or right skewed tree), we need to stroe `n` nodes in the stack. 
*/
