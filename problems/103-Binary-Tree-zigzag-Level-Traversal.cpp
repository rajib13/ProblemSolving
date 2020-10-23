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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ret;
        if(root == NULL) return ret;
        
        queue<TreeNode*> nodes; // for level order traversal we apply BFS on the tree.
        
        nodes.push(root);
        int level = 0; 
        while(!nodes.empty()){
            int qSize = nodes.size();
            vector<int> levelNodes;
            for(int i = 0; i<qSize; i++){
                TreeNode* root = nodes.front(); nodes.pop();
                levelNodes.push_back(root->val);
                if(root->left) nodes.push(root->left);
                if(root->right) nodes.push(root->right);
            }
            if(level % 2) reverse(levelNodes.begin(), levelNodes.end()); // Finally reversing the order for zigzag. 
            ret.push_back(levelNodes);
            level++; // increment of the level
        }
    return ret;         
    }
};

/*Complexity analysis:
    Time: O(n), where n is the number of nodes in the given tree.
    Space: O(n), in worst case, full binary tree, we need to store n/2 nodes in the queue and levelNode vector.
*/
