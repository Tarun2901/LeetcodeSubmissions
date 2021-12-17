# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        lst = []
        if not root:
            return lst;
        q = deque();
        q.append(root);
        while len(q)>0:
            size = len(q)
            while size>0:
                if size == 1:
                    lst.append(q[0].val);
                node = q[0];
                q.popleft();
                if node.left:
                    q.append(node.left);
                if node.right:
                    q.append(node.right)
                size-=1
        return lst;