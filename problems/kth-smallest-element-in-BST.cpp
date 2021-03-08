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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> nodes;
        while(!nodes.empty() or root != nullptr){
            while(root != nullptr){
                nodes.push(root);
                root = root->left;
            }
            root = nodes.top(); nodes.pop();
            if(--k == 0) return root->val;
            root = root->right;
        }
        return 0;
    }
};

/*
    Complexity Analysis:
    Time: O(n), in worst case (left skewed tree) we need to scan all elements. 
    Space: O(n), if the tree is left skewed tree, then the stack needs to store all nodes down to the leaf.
*/
