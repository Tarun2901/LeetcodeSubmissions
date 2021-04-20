/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    
    
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // 3 cases here for a BST -> Either the data at node is greater than both the data of p and q, or it is less than the data of both p and q and at last, it is somewhere between the data of p and q.
        
        if(root.val<p.val && root.val <q.val)
        {
            return lowestCommonAncestor(root.right,p,q);
        }
        else if(root.val>p.val && root.val > q.val)
        {
            return lowestCommonAncestor(root.left,p,q);
        }
        else
        {
            return root;
        }
    }
}