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
    TreeNode* invertTree(TreeNode* root) {
        /*Approach 2: Recursive solution*/
        if(root == nullptr) return root;
        TreeNode* right = invertTree(root->right);
        TreeNode* left = invertTree(root->left);
        root->right = left;
        root->left = right;
        return root;
    }
};


/*
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Approach 1: Iterative
        if(root == nullptr) return root;
        TreeNode* head = root;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int qSize = q.size();
            for(int i = 0; i < qSize; i++){
                root = q.front(); q.pop();
                swap(root->left, root->right);
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
        }
        return head;
    }
};

*/
