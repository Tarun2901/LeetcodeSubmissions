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
    public int sum = 0;
    
    public void rwsol(TreeNode root)
    {
        if(root == null)
        {
            return;
        }
        rwsol(root.right);
        int od = root.val;
        root.val = sum+root.val;
        sum+=od;
        rwsol(root.left);
    }
    public TreeNode convertBST(TreeNode root) {
        rwsol(root);
        return root;
    }
}