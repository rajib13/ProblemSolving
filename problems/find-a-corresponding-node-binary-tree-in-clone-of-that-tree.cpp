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
    TreeNode* getTargetCopy(TreeNode* root1, TreeNode* root2, TreeNode* target) {
        stack<TreeNode*> nodes;
        while(!nodes.empty() || root1 != nullptr){
            while(root1 != nullptr){
                nodes.push(root1);
                nodes.push(root2);
                root1 = root1->left;
                root2 = root2->left;
            }
            
            root2 = nodes.top(); nodes.pop();
            root1 = nodes.top(); nodes.pop();
            if(root1 == target) return root2;
            
            root1 = root1->right;
            root2 = root2->right;
        }
        return nullptr;
    }
};

/*
    Complexity analysis: 
    Time: O(n), where `n` is the number of nodes in the given tree, as we need to traverse the whole tree.
    Space: O(height), in the worst case (left or right skewed tree) we need to store the height of the tree into the stack. 
*/
