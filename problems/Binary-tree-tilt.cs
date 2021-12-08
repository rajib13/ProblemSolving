/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public int FindTilt(TreeNode root) {
        dfs(root);
        return gap;
    }
    
    private int dfs(TreeNode root) {
        if(root == null) return 0;
        
        int left = dfs(root.left);
        int right = dfs(root.right);
        gap += Math.Abs(left - right);
        return root.val + left + right;
    }
    
    private int gap = 0;
}

/*
    Complexity analysis:
    Time: O(n), where `n` is the number of nodes in the given tree, as we need to scan every element of the tree. 
    Space: O(h), where `h` is the height of the tree, in worst case (left or right skewed tree) the height could be `n`. 
*/
