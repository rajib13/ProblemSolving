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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(root == NULL) return ret; // Edge Case;

        queue<TreeNode*> nodes; // Queue for BFS
        nodes.push(root);
        
        while(!nodes.empty()){
            int qSize = nodes.size(); 
            for(int i =0 ; i < qSize; i++){
                root = nodes.front(); nodes.pop();
                if(root->left){
                    nodes.push(root->left);
                } 
                if(root->right){
                    nodes.push(root->right);
                } 
                if(i == qSize - 1) ret.push_back(root->val);
            }
        }
        return ret;
    }
};

/*
    Complexity analysis:
    Time: O(n), where n is the number of nodes in the tree.
    Space: O(n), in worst case (full binary tree) we need to store at most n/2 nodes in the queue.
*/
