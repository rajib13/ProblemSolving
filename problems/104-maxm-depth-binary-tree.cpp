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
    int maxDepth(TreeNode* root) {
     return root == NULL? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

/*
    Complexity analysis:
    Time: O(n), where n is the number of nodes of the given tree.
    Space: O(n), in worst case, if the given tree is left or skewed tree then we need to store all n nodes in the stack.
*/

/*
Note:   if we were asked to find the max depth by counting edges then in base case
        we would return -1. That means when there is no node we should return -1
        because a node without child has no edge, it should return 0 and so if there is no 
        root then -1. 
        
        See Hackerrank problem: https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=trees

*/
