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
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        bool direction = true; // True means left to right, False otherwise. 
        
        while(!nodes.empty()){
            int qSize = nodes.size();
            vector<int> levelNodes(qSize);
            
            for(int i = 0; i < qSize; i++){
                TreeNode* root = nodes.front(); nodes.pop();
                int index = direction ? i : (qSize - 1 - i);
                
                levelNodes[index] = root->val;
                if(root->left) nodes.push(root->left);
                if(root->right) nodes.push(root->right);
            }
            ret.push_back(levelNodes);
            direction = !direction; 
        }
    return ret;         
    }
};

/*
    Complexity Analysis: 
    Time: O(n), as we need to scan all nodes.
    Space: O(L), where L is the highest nodes in a level. O(n) for full binary tree. 
*/
