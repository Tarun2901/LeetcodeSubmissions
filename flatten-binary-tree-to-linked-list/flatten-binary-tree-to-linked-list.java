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
/*
Preorder traversal
*/
class Solution {
    
    public TreeNode flat(TreeNode root)
    {
        if(root == null)
        {
            return null;
        }
        TreeNode a = null;
        TreeNode b = null;
        if(root.left!=null)
        {
            a = flat(root.left);
        }
        if(root.right!=null)
        {
            b = flat(root.right);
        }
        if(a == null && b == null)
        {
            return root;
        }
        if(a!=null && b!=null)
        {
            TreeNode itr = a;
            while(itr.right!=null)
            {
                itr = itr.right;
            }
            itr.right = b;
            root.right = a;
            root.left = null;
            return root;
        }
        if(a == null && b!=null)
        {
            root.right = b;
            return root;
        }
        if(a!=null && b == null)
        {
            root.right = a;
            root.left = null;
            return root;
        }
        return root;
    }
    public void flatten(TreeNode root) {
            flat(root);
    }
}