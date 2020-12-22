/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == nullptr) return ret;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()){
            int qSize = nodes.size();
            vector<int> level;
            for(int i = 0; i < qSize; i++){
                TreeNode* root = nodes.front(); nodes.pop();
                level.push_back(root->val);
                if(root->left) nodes.push(root->left);
                if(root->right) nodes.push(root->right);
            }
            ret.push_back(level);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
/*      
    Complexity analysis: 
    Time: O(n), where n is the total number of nodes in the given tree.
    Space: O(n), in case of full binary tree, we need to store n/2 nodes into the queue.
*/
