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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        //Check if head is null or not
        
        if(head == null)
        {
            return head;
        }
        //Create a dummy node
        ListNode fake = new ListNode(0);
        fake.next = head;
        ListNode pre = fake;
        
        //Iterate pre to one position before left
        
        for(int i = 0; i<left-1;i++)
        {
            pre = pre.next;
        }
        ListNode curr = pre.next;
        ListNode next1 = curr.next;
        //Iterate over the sub-list while maintaining pre at its position and handling connections of nodes for reversal
        for(int i = 0;i<right-left;i++)
        {
            curr.next = next1.next;
            next1.next = pre.next;
            pre.next = next1;
            next1 = curr.next;
        }
        return fake.next;
        
    }
}