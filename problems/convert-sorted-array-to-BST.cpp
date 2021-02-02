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
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int start, int end){
         if(start > end) return nullptr;
         int mid = (start + end)/2;
         TreeNode* root = new TreeNode(nums[mid]);
         root->left = sortedArrayToBSTHelper(nums, start, mid - 1);
         root->right = sortedArrayToBSTHelper(nums, mid+1, end);
        
         return root; 
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTHelper(nums, 0, nums.size()-1);
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the given array, as we need to scan all elements of the array to put on the BST.
    Space: O(h), where `h` is the height of the given tree that we need to store in the stack space;
*/
