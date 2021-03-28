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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode current = head;
         if(current == null)
        {
            return null;
        }
        
       
       while(current.next!=null)
       {  ListNode temp = current.next;
           if(temp.val == current.val)
           {   temp = temp.next;
               current.next = temp;
           }
           else
           {
               current = current.next;
           }
       }
        return head;
        
    }
}