class Solution(object):
    def lowestCommonAncestor(self, root, p, q):  
        if root:
            if root.val == p.val or root.val == q.val:
                return root;
            l,r = self.lowestCommonAncestor(root.left,p,q),self.lowestCommonAncestor(root.right,p,q);
            if l and r:
                return root;
            return l if l else r
        return None