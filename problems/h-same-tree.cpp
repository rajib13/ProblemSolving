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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        /*Approach 2: recursion. O(n) and O(log n) space - DFS.*/
        if(p == NULL and q == NULL ) return true; // crucial, because in the next line(s) we try to access the value/childs
        
        if(p and q == NULL || q and p == NULL || p->val != q->val) return false;
        
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
        
    }
};
 
 

/*Approach 1 : O(n) runtime and O(log n) space - BFS level order traversal.
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p and q == NULL || q and p == NULL) return false;
        
        stack<TreeNode*> nodesP;
        stack<TreeNode*> nodesQ;
        
        while(!nodesP.empty() or !nodesQ.empty() or p != NULL){
            while( p != NULL or q!= NULL){
                
                if(q == NULL or p == NULL or p->val != q->val) return false;
                nodesQ.push(q);
                nodesP.push(p);
                p = p->left;
                q = q->left;
            }
            p = nodesP.top(); nodesP.pop();
            q = nodesQ.top(); nodesQ.pop();
            
            if(p->val != q->val) return false;
            p = p->right;
            q = q->right;
        }
        return true;
        
    }
};

/*/


/*Test Cases

[1,2,3]
[1,2,3]
[1]
[2]
[1,2,1]
[1,1,2]
[1,2,3,4,5,6]
[1,2,3,4,6,5]
[1,2,3,4]
[1,2,3,4,6,5]
[1,2,3,4,5,6]
[1,2,3,4]

*/
