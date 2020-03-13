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
    
        /*Apporach: Traverse the both trees at the same time. */
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
