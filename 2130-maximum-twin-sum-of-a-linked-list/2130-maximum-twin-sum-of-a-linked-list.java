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
    
     public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        
        while(curr!=null)
        {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    public int pairSum(ListNode head) {
        ListNode dummy = new ListNode();
        ListNode p = dummy;
        ListNode temp = head;
        int size = 0;
        while(temp!=null)
        {
            ListNode node = new ListNode(temp.val);
            p.next = node;
            p = node;
            temp = temp.next;
            size++;
        }
        dummy.next = reverseList(dummy.next);
        p = dummy.next;
        int l = size;
        int r = 0;
        temp = head;
        int mxsum = 0;
        while(r<l)
        {
            int sum = p.val + temp.val;
            mxsum = Math.max(mxsum,sum);
            p = p.next;
            temp = temp.next;
            r++;
            l--;
        }
        return mxsum;
    }
}