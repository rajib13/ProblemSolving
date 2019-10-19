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
        
        vector<int> levelNodes;
        queue<TreeNode*> nodes;
        
        nodes.push(root);
        int level = 0; 
        while(!nodes.empty()){
            int qSize = nodes.size();
            
            for(int i = 0; i<qSize; i++){
                TreeNode* root = nodes.front(); nodes.pop();
                levelNodes.push_back(root->val);
                if(root->left) nodes.push(root->left);
                if(root->right) nodes.push(root->right);
            }
            if(level % 2) reverse(levelNodes.begin(), levelNodes.end());
            ret.push_back(levelNodes);
            levelNodes.clear();
            level++;
        }
    return ret;         
    }
};
