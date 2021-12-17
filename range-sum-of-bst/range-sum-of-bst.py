# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        if not root:
            return 0;
        sumHere = 0;
        if high<root.val:
            sumHere+=self.rangeSumBST(root.left,low,high);
        elif low>root.val:
            sumHere+=self.rangeSumBST(root.right,low,high);
        else:
            sumHere+=root.val;
            sumHere+=self.rangeSumBST(root.left,low,high);
            sumHere+=self.rangeSumBST(root.right,low,high);
        return sumHere
        