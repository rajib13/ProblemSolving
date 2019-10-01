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
    bool findTarget(TreeNode* root, int target) {
        
       /*Approach : Using vector. O(n) time and O(n) space complexity.*/
        
        stack<TreeNode*> nodes;
        
        vector<int> nums;
        
        while(root != NULL or !nodes.empty()){
            
            while(root != NULL){
                nodes.push(root);
                root = root->left;
            }
            
            root = nodes.top(); nodes.pop();
            
            nums.push_back(root->val);
            root = root->right;
        }
        
        int leftPointer = 0, rightPointer = nums.size() - 1;
        
        while(leftPointer < rightPointer){
            int sum = nums[leftPointer] + nums[rightPointer];
            
            if(sum == target) return true;
            else if(sum > target) rightPointer--;
            else leftPointer++;
        }
    
        
        return false;
     }
};



/*Test Cases: 

[]
1
[1]
2
[1]
1
[5,3,6,2,4,null,7]
11
[5,3,6,2,4,null,7]
12
[5,3,6,2,4,null,7]
16

*/


/*
class Solution {
public:
    bool findTarget(TreeNode* root, int target) {
        
        stack<TreeNode*> left;
        stack<TreeNode*> right;
        
        TreeNode* head = root;
        bool leftPointer = true, rightPointer = true;
        
        while(!left.empty() || !right.empty() || root != NULL){
            
            while(root != NULL and leftPointer == true){
                    left.push(root);
                    root = root->left;
            }
            while (head != NULL and rightPointer == true){
                    right.push(head);
                    head = head->right;
                }
            }
            if (leftPointer) root = left.top(); left.pop();
            if (rightPointer) head = right.top(); right.pop();
 
            int sum = root->val + head->val;
            cout <<root->val<<" "<<head->val;
            if(sum == target) return true;
            else if (sum > target){
                head = head->left; 
                leftPointer = false;
                rightPointer = true;
            } 
            else{
                root = root->right;
                leftPointer = true;
                rightPointer = false;
            }
        
        return false;
     }
};

*/
