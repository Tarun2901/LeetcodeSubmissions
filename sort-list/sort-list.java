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
    {   if(head == null || head.next == null)
    {
        return head;
    }
        ListNode slow = head;
        ListNode fast = head;
        while(fast.next!=null && fast.next.next!=null)
        {
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }
    public ListNode merge2SLL(ListNode l1,ListNode l2)
    {   
        if(l1==null||l2==null)
        {
            return l1!=null?l1:l2;
        }
        ListNode c1 = l1;
        ListNode c2 = l2;
        ListNode dummy = new ListNode(-1);
        ListNode prev = dummy;
        while(c1!=null&&c2!=null)
        {
            if(c1.val<c2.val)
            {
                prev.next = c1;
                c1 = c1.next;
            }
            else
            {
                prev.next = c2;
                c2 = c2.next;
            }
            prev = prev.next;
        }
        prev.next = c1!=null?c1:c2;
        return dummy.next;
    }
    public ListNode sortList(ListNode head) {
        if(head == null || head.next ==null)
        {
            return head;
        }
        //Find the middle node
        ListNode mid = midNode(head);
        //Find the starting node for the second half
        ListNode nH = mid.next;
        //Divide the linked list into two halves
        mid.next = null;
        //Recursively sort the two halves of the linked list
        ListNode l1 = sortList(head);
        ListNode l2 = sortList(nH);
        //Merge the two sorted halves of the linked list and return
        return merge2SLL(l1,l2);
    }
}