/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int count = 0;
    public int goodNodes(TreeNode root) {
        if(root == null) return 0;
        dfs(root, root.val);
        return count;
    }
    
    private void dfs(TreeNode root, int maxSoFar){
        if(root == null) return;
        if(root.val >= maxSoFar) count++;
        maxSoFar = Math.max(maxSoFar, root.val);
        dfs(root.left, maxSoFar);
        dfs(root.right, maxSoFar);
    }
}

/*
    Complexity analysis:
    Time: O(n), where `n` is the number of nodes of the given tree, as we need to scan every node of the tree.
    Space: O(n), in worst case, if the given tree is left or skewed tree then we need to store all `n` nodes in the recursion call    stack.
*/
