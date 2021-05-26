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
    
    
    public ListNode midNode(ListNode head)
    {
        ListNode slow = head;
        ListNode fast = head;
        while(fast.next!=null && fast.next.next!=null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    public ListNode reverse(ListNode head)
    {
        ListNode prev = null;
        ListNode curr = head;
        ListNode forw = null;
        while(curr!=null)
        {
            forw = curr.next;
            curr.next = prev;
            //move 
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    public void reorderList(ListNode head) {
        ListNode mid = midNode(head);
        ListNode sh = mid.next;
        mid.next = null;
        ListNode sh1 = reverse(sh);
        ListNode c1 = head;
        ListNode c2 = sh1;
        ListNode f1 = null;
        ListNode f2 = null;
        while(c1!=null && c2!=null)
        {
            //Backup 
            f1 = c1.next;
            f2 = c2.next;
            //Connect
            c1.next = c2;
            c2.next = f1;
            //move 
            c1 = f1;
            c2 = f2;
        }
    }
}