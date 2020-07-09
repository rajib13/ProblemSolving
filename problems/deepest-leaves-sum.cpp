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
    int deepestLeavesSum(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int levelSum = 0;
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()){
            levelSum = 0; 
            int qSize = nodes.size();
            for(int i = 0 ; i < qSize; i++){
                root = nodes.front(); nodes.pop();
                levelSum += root->val;
                if(root->left) nodes.push(root->left);
                if(root->right) nodes.push(root->right);
            }
            
        }
        return levelSum;
        
    }
};

/*Complexity analysis:
Time: O(n), as we scan all the tree nodes once.
Space: O(n), in full binary tree the number of nodes in the deepest level would be n/2 that we need to store in the queue.
*/
