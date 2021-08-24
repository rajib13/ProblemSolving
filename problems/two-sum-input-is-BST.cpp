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
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        stack<TreeNode*> nodes;
        
        while(!nodes.empty() or root){
            while(root){
                nodes.push(root);
                root = root->left;
            }
            root = nodes.top(); nodes.pop();
            nums.push_back(root->val);
            root = root->right;
        }
        
        int i = 0; 
        int j = nums.size() - 1;
        
        while(i < j){
            int value = nums[i] + nums[j];
            if(value == k) return true;
            else if (value > k) j--;
            else i++;
        }
        
        return false;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the number of nodes in the given BST.
    Space: O(n), since we need an auxilary vector to store the nodes value.
*/
