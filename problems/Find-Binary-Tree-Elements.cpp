/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    vector<int> ret;
    FindElements(TreeNode* root) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        while(!nodes.empty()){
            int qSize = nodes.size();
            for(int i = 0 ; i  < qSize; i++){
                root = nodes.front(); nodes.pop();
                int value = root->val == -1 ? 0: root->val;
                
                if(root->left) {
                    ret.push_back(value * 2 + 1);
                    nodes.push(root->left);
                    root->left->val = value * 2  + 1;
                }
                if(root->right) {
                    ret.push_back(value * 2 + 2);
                    nodes.push(root->right);
                    root->right->val = 2 * value + 2;
                }
            }
            
            
        }
        
    }
    
    bool find(int target) {
        if(target == 0) return true;
        
        int start = 0; 
        int end = ret.size() - 1;
        while(start <= end){
            int mid = (start + end)/2;
            if(ret[mid] == target) return true;
            else if(ret[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
