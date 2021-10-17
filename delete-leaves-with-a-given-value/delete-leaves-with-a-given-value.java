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

    public TreeNode travel(TreeNode node,int target)
    {
        if(node == null)
        {
            return null;
        }
        TreeNode rleft = travel(node.left,target);
        TreeNode rright = travel(node.right,target);
        node.left = rleft;
        node.right = rright;
        if(rleft == null && rright == null && node.val == target)
        {
            return null;
        }
        return node;
    }
    
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        TreeNode node = root;
        root = travel(node,target);
        return root;
    }
}