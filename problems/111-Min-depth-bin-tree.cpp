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
        if(root == NULL) return 0;
        if(root->right == NULL) return 1 + minDepth(root->left);
        
        else if(root->left == NULL) return 1 + minDepth(root->right); 
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

/*
    Complexity analysis:
    Time: 0(n), in worst case, if the given tree is a full binary tree, we need to scan all nodes once.
    Space: O(logn), for the recursion stack space. 
*/


/*
    int minDepth(TreeNode* root) {
        
        // Approach 1: 100% space optimized. O(n) runtime, O(n) space - BFS level order traversal
        
        if(root == NULL) return 0; // Edge Case;

        queue<TreeNode*> nodes; // Queue for BFS
        nodes.push(root); // Push root to the queue so that while loop works.
        
        int depth = 1; 
        while(!nodes.empty()){
            
            int qSize = nodes.size(); // it is crucial to determine here, if you want to find the Q size at for loop, there will be a problem, think what?
            
            for(int i =0 ; i < qSize; i++){
            
                root = nodes.front(); nodes.pop();
                
                if(root->left == NULL and root->right == NULL) return depth;

                if(root->left){
                    nodes.push(root->left);
                } 

                if(root->right){
                    nodes.push(root->right);
                } 
            }
            depth++;
        }
        return depth; 
    }

*/
