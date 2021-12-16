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
    public TreeNode buildtree(int[] postorder, int psi,int pei,int[] inorder,int isi,int iei)
    {
        if(psi>pei)
        {
            return null;
        }
        TreeNode node = new TreeNode(postorder[pei]);
        int idx = isi;
        while(inorder[idx]!=postorder[pei])
        {
            idx++;
        }
        int count = idx - isi;
        node.left = buildtree(postorder,psi,psi+count-1,inorder,isi, idx-1);
        node.right = buildtree(postorder,psi+count,pei-1,inorder,idx+1, iei);
        return node;
    }
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if(postorder.length==0)
        {
            return null;
        }
        int n = postorder.length;
        return buildtree(postorder,0,n-1,inorder,0,n-1);
    }
}