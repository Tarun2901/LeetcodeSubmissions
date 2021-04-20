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
   ArrayList<TreeNode> path1;
   ArrayList<TreeNode> path2;
    public boolean find1(TreeNode root, int data)
    {
        if(root == null)
        {
            return false;
        }
        if(root.val == data)
        {
            path1.add(root);
            return true;
        }
        boolean lfind = find1(root.left,data);
        if(lfind)
        {
            path1.add(root);
            return true;
        }
        boolean rfind = find1(root.right,data);
        if(rfind)
        {
            path1.add(root);
            return true;
        }
        return false;
    }
    
    public boolean find2(TreeNode root, int data)
    {
        if(root == null)
        {
            return false;
        }
        if(root.val == data)
        {
            path2.add(root);
            return true;
        }
        boolean lfind = find2(root.left,data);
        if(lfind)
        {
            path2.add(root);
            return true;
        }
        boolean rfind = find2(root.right,data);
        if(rfind)
        {
            path2.add(root);
            return true;
        }
        return false;   
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        path1 = new ArrayList<>();
        boolean b1 = find1(root,p.val);
        path2 = new ArrayList<>();
        boolean b2 = find2(root,q.val);
        int i = 0;
        int j = 0;
        for(TreeNode ele1:path1)
        {
            for(TreeNode ele2:path2)
            {
                if(ele1 == ele2)
                {
                    return ele1;
                }
            }
        }
        return root;
    }
}