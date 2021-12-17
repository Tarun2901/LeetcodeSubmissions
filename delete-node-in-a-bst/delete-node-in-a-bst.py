# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maximum(self,node):
        while node.right:
            node = node.right;
        return node.val;
    def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """
        if not root:
            return None
        
        if key<root.val:
            root.left = self.deleteNode(root.left,key)
        elif key>root.val:
            root.right = self.deleteNode(root.right,key)
        else:
            if not root.left or not root.right:
                node = root.left if root.left else root.right;
                return node;
            maxleft = self.maximum(root.left)
            root.val = maxleft;
            root.left = self.deleteNode(root.left,maxleft);
        return root;