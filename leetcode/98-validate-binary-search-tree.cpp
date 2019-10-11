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

    bool isValidBST(TreeNode* root) {
        
        if(root == NULL) return true; //Edge case
        
        /*
            Idea: Like inorder traversal we will find out the smallest value node and then will make sure every node is less than the minn.
            minn is initially zero and every time will update with the root. 
        */
        stack<TreeNode*> nodes;
        
        long minn = long(INT_MIN) - 1; 
        cout<<minn<<endl;
        
        while(root != NULL || !nodes.empty()){      
            while(root != NULL){
                nodes.push(root);
                root = root->left;
            }
            
            root = nodes.top(); nodes.pop();
            
            if(minn >= root->val) return false;
            minn = root->val; 
            root = root->right;
        }

        
        return true;
        
    }
};


/* Approach 2: recursive O(N) time and space complexity (since we keep up to the entire tree)

    bool validateHelper(TreeNode* root, long minn, long maxx){ //receive as LONG otherwise in line 18 there will be integer overflow error if root->val == INT_MAX
        if(root == NULL) return true;
        
        if(root->val < minn || root->val > maxx) return false;
        
        return validateHelper(root->left, minn, (long) root->val-1) && validateHelper(root->right, (long) root->val+1, maxx); // casting to long
        
    }
    bool isValidBST(TreeNode* root) {
        return validateHelper(root, INT_MIN, INT_MAX); // send INT_MIN/MAX  
        
        
    }


*/

/*

[2,1,3]
[5,3,7,2,4,6,8,1,null,null,null,null,null,null,10]
[]
[1]
[-2147483648]


*/
