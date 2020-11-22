/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> stck;
    BSTIterator(TreeNode* root) {
        pushIntoStack(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* head = stck.top(); stck.pop();
        int ret = head->val;
        head = head->right;
        pushIntoStack(head);
        return ret;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stck.empty();
    }
    
    void pushIntoStack(TreeNode* root){
        while(root != nullptr){
            stck.push(root);
            root = root->left;
        }
    }
};

/*
    Complexity analysis:
    Time: O(n), where n is the number of nodes in the given BST.
    Space: O(h), we store the height of nodes in the stack.  
   */

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
