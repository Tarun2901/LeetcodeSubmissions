def f(root):
    if root:
        ld,lp = f(root.left);
        rd,rp = f(root.right);
        return 1+max(ld,rd),max(lp,rp,1+rd+ld)
    return 0,0
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        return f(root)[1]-1;
        