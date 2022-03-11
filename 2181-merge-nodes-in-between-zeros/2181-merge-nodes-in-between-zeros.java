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
    public ListNode mergeNodes(ListNode head) {
        ListNode dummy = new ListNode(-1);
        ListNode p = dummy;
        ListNode temp = head;
        int curr = 0;
        while(temp!=null)
        {
            if(temp.val == 0 && curr > 0)
            {
                ListNode newNode = new ListNode(curr);
                p.next = newNode;
                p = newNode;
                curr = 0;
            }
            else if(temp.val>0)
            {
                curr+= temp.val;
            }
            temp = temp.next;
        }
        return dummy.next;
    }
}