/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null || head.next == null)
        {
            return null;
        }
        ListNode slow = head;
        ListNode fast = head;
        while(fast!=null && fast.next!=null)
        {
            fast = fast.next.next;
            slow = slow.next;
            if(slow == fast)
            {   //cycle exists
                break;
            }
        }
        if(slow!=fast)
            {
                //cycle does not exist
                return null;
            }
        //For finding the node where cycle begins, put slow ptr back to head and increment slow and fast by 1 until they don't meet
        slow = head;
        while(slow!=fast)
        {
            slow = slow.next;
            fast = fast.next;
        }
        return slow;
    }
}