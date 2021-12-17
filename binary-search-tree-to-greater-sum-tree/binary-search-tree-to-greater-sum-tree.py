# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
sm = 0;
def solve(root):
    global sm
    if root:
        solve(root.right)
        od = root.val;
        root.val = sm+root.val;
        sm+=od;
        solve(root.left);
    return;
class Solution(object):
    def bstToGst(self, root):
        solve(root);
        global sm
        sm = 0;
        return root;
        
        