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
    public ListNode oddEvenList(ListNode head) {
        if(head == null || head.next == null)
        {
            return head;
        }
        ListNode odd = head;
        ListNode even = head.next;
        ListNode remember = even;
        while(even!=null && even.next!=null)
        {
            ListNode temp = even.next;
            odd.next = temp;
            even.next = temp.next;
            if(odd.next!=null)
            {
                odd = odd.next;
            }
             if(even.next!=null)
            {
                even = even.next;
            }
        }
        odd.next = remember;
        return head;
    }
}