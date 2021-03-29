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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode temp1 = l1;
        ListNode temp2 = l2;
        ListNode res = new ListNode(0);
        ListNode head1 = res;
        while(temp1 != null && temp2 != null)
        {
            if(temp1.val<=temp2.val)
            {  

                res.next = temp1;
                temp1 = temp1.next;
            }
            else
            {
               
                res.next = temp2;
                temp2 = temp2.next;
            }
            res = res.next;
        }
        if(temp1!=null)
        {
             res.next = temp1;
        }
        if(temp2!=null)
        {
            res.next = temp2;
        }
        return head1.next;
    }
}