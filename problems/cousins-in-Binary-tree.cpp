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
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        while(!nodes.empty()){
            int qSize = nodes.size();
            bool flag = false;
            for(int i = 0; i < qSize; i++){
                root = nodes.front(); nodes.pop();
                if(root->left) nodes.push(root->left);
                if(root->right) nodes.push(root->right);
                
                int left = root->left ? root->left->val : 0;
                int right = root->right ? root->right->val : 0;
                if((left == x and right == y) or (left == y and right == x)) return false;
                if(left == x or left == y){
                    if(flag) return true; 
                    else flag = true;
                } 
                if(right == x or right == y){
                    if(flag) return true;
                    else flag = true;
                }
                
            }
        }
        return false;
    }
};



/*
Complexity: 
Time : O(n), where n is the total number of nodes in the given tree.
Space : O(n), because in a full binary tree, no. of leaf nodes = n/2 (where n is total no of nodes).*/
