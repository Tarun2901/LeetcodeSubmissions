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
    public ListNode partition(ListNode head, int x) {
         ListNode temp = head;
    
         ListNode greater = new ListNode(-1);
         ListNode itr1 = greater;
         ListNode smaller = new ListNode(-1);
         ListNode itr2 = smaller;
         while(temp!=null)
         {
             ListNode store = temp;
             temp = temp.next;
             if(store.val<x)
             {
                 itr2.next = store;
                 itr2 = itr2.next;
                 itr2.next = null;
             }
             else if(store.val>=x)
             {
                 itr1.next = store;
                 itr1 = itr1.next;
                 itr1.next = null;
             }
         }
        itr2.next = greater.next;
        return smaller.next;
    }
}