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
        // root1 is the root of the original tree and the root2 represents the root of the cloned tree.
        
        /*Apporach: In-order traverse the both trees at the same time, and push root1 to the stack 
            first and then the root2. Once we got the target node as same as root1 node, we can 
            return the root2 as reference.*/
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

/*Complexity: My algorithm runs in O(n) time, as we need to traverse the whole tree to find the target. 
O(height) space complexity, as at the worst case we need to store the height of the tree into the stack. */
