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
    int minDepth(TreeNode* root) {
        /*Recursion, better time but space is so poor (33%)*/
        if(root == NULL) return 0;
        if(root->right == NULL) return 1 + minDepth(root->left);
        
        else if(root->left == NULL) return 1 + minDepth(root->right); 
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};



/*
    int minDepth(TreeNode* root) {
        
        
        // My solution: 100% space optimized.
        
        if(root == NULL) return 0; // Edge Case;

        queue<TreeNode*> nodes; // Queue for BFS
        nodes.push(root); // Push root to the queue so that while loop works.
        
        int minn = 1; 
        while(!nodes.empty()){
            
            int qSize = nodes.size(); // it is crucial to determine here, if you want to find the Q size at for loop, there will be a problem, think what?
            
            for(int i =0 ; i < qSize; i++){
            
                root = nodes.front(); nodes.pop();
                
                if(root->left == NULL and root->right == NULL) return minn;

                if(root->left){
                    nodes.push(root->left);
                } 

                if(root->right){
                    nodes.push(root->right);
                } 
            }
            minn++;
        }
        return minn; 
    }

*/
/*
Test Cases: 

[3,9,20,null,null,15,7]
[]
[8]
[2,3]
[1,2,3,4,5,6,7,8,9]
[1,2,3,4,5,6,7,8,9,null,null,8,null,null,6]
[1,null,2,null,3,4,null,5,null,6,7,null]

*/
