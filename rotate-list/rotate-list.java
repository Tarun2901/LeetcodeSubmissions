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
    public ListNode rotateRight(ListNode head, int k) {
            if(head == null)
            {
                return null;
            }
            if(head.next == null)
            {
                return head;
            }
            int count = 0;
            ListNode temp = head;
            while(temp!=null)
            {
                temp = temp.next;
                count++;
            }
            if(k>count)
            {
                k = k%count;
            }
            if(k==count)
            {
                return head;
            }
            int x = 0;
            ListNode temp1 = head;
            while(x<count-k-1)
            {
                temp1 = temp1.next;
                x++;
            }
            ListNode nHead = temp1.next;
            temp1.next = null;
            
            ListNode list1 = reverseList(head);
            ListNode list2 = reverseList(nHead);
        
            ListNode fake = new ListNode(-1);
            ListNode prev = fake;
            fake.next = list1;
            while(prev.next!=null)
            {
                prev = prev.next;
            }
            prev.next = list2;
            ListNode ansHead = reverseList(fake.next);
            return ansHead;
        }
}