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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {   
        
        vector<vector<int>> ret;
        if(root == NULL) return ret; // Edge Case;
        
        vector<int> levelNodes; // To store the level order nodes. 

        queue<TreeNode*> nodes; // Queue for BFS
        nodes.push(root); // Push root to the queue so that while loop works.
        
        while(!nodes.empty()){
            
            int qSize = nodes.size(); // it is crucial to determine here, if you want to find the Q size at for loop, there will be a problem, think what?
            
            for(int i =0 ; i < qSize; i++){
            
                root = nodes.front(); nodes.pop();
                levelNodes.push_back(root->val);

                if(root->left){
                    nodes.push(root->left);
                } 

                if(root->right){
                    nodes.push(root->right);
                } 
            }
            ret.push_back(levelNodes);
            levelNodes.clear();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
/*
    Complexity analysis:
    Time: O(n), where n is the number of nodes in the given tree. 
    Space: O(n), in worst case, full binary tree, we need to store n/2 nodes in the queue.
*/
