/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if(root == nullptr) return ret;
        queue<Node*> nodes;
        nodes.push(root);
        
        while(!nodes.empty()){
            int qSize = nodes.size();
            vector<int> curr;
            for(int i = 0; i < qSize; i++){
                root = nodes.front(); nodes.pop();
                curr.push_back(root->val);
                for(int j = 0; j < root->children.size(); j++){
                    nodes.push(root->children[j]);
                }
            }
            ret.push_back(curr);
        }
        return ret;
    }
};

/*
    Complexity analysis:
    Time: O(n), where `n` is the number of nodes in the given tree.
    Space: O(n), since we need to store intermediate nodes into a queue. 
*/
