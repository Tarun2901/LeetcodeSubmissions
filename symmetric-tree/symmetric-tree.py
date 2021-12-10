# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isMirror(self,root1,root2):
        if not root1 and not root2:
            return True;
        if root1 and not root2:
            return False;
        if not root1 and root2:
            return False;
        b1 = root1.val == root2.val;
        b2 = self.isMirror(root1.left,root2.right);
        b3 = self.isMirror(root1.right,root2.left);
        return b1 and b2 and b3;
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        root1 = root.left;
        root2 = root.right;
        res = self.isMirror(root1,root2);
        return res
        