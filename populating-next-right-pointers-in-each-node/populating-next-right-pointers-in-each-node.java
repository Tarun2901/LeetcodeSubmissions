/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

        /*
                         1(tnode) => tnode.left.next = tnode.right + some additional statements that make sense for next lvl                          /  \
                      2---> 3    (root at 2, tnode = root, tnode.left.next = tnode.right, Now we have to travel to right)
                     / \   / \    (tnode.right = tnode.next.left) (Once we do this we can travel to 3 by tnode = tnode.next)
                    4-->5->6->7     (Node first part 6->7 is done easily but once we are on second stmnt of tnode.right we
                                      need a not null check for tnode.next when executing tnode.right = tnode.next.left)
        */

class Solution {
    public Node connect(Node root) {
        //Using the concept of a travelling node for a level until tnode.next == NULL => It is the last node on that
        //particular level
        if(root == null)
        {
            return root;
        }
        Node head = root;
        while(head.left!=null)
        {
            Node tnode = head;
            while(tnode!=null)
            {
                tnode.left.next = tnode.right; 
                if(tnode.next!=null)
                {
                    tnode.right.next = tnode.next.left;
                }
                tnode = tnode.next;
            }
            head = head.left;
        }
        return root;
    }
}