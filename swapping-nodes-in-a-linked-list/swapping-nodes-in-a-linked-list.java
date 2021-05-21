/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode nodebegin(ListNode head,int k)
    {
        ListNode curr = head;
        int count = 1;
        while(count!=k)
        {
            curr = curr.next;
            count++;
        }
        return curr;
    }
    public ListNode nodefromend(ListNode head,int k)
    {
        ListNode fast = head;
        ListNode slow = head;
        int count = 0;
        while(count!=k)
        {
            fast = fast.next;
            count++;
        }
        while(fast!=null)
        {
            fast = fast.next;
            slow = slow.next;
        }
        return slow;
    }
    public ListNode swapNodes(ListNode head, int k) {
        ListNode begin = nodebegin(head,k);
        ListNode end = nodefromend(head,k);
        int temp = begin.val;
        begin.val = end.val;
        end.val = temp;
        return head;
    }
}