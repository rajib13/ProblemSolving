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
        nodes.push(root); // Push root to the queue so that while loop works.
        
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
[1,2,3,6,5,6,4]
[1,null,2,null,3,null,5]
[1,2,null,3,null,5]
[1,2,3,6,5]
*/
