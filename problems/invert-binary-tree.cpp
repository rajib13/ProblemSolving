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

/*
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Approach 2: Recursive solution
        if(root == nullptr) return root;
        TreeNode* right = invertTree(root->right);
        TreeNode* left = invertTree(root->left);
        root->right = left;
        root->left = right;
        return root;
    }
};
*/


/*
    Complexity Analysis:
    Time: O(n), as we need to scan all nodes at least once, where `n` is the number of nodes of the given tree.
    Space: O(n), as in worst case the queue (resp. in recursive approach for the DFS, call stack) needs to hold [n/2] (resp. height of the tree h) nodes. 

*/
