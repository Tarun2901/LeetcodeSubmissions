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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
         int count = 0;
         int countb = 0;
         ListNode h1 = list1;
         ListNode endb = list1;
         ListNode h2 = list2;
         while(countb!=b)
         {
            endb = endb.next;
            countb++;
         }
        endb = endb.next;
         while(count!=a-1)
         {
            h1 = h1.next;
            count++;
         }
        h1.next = h2;
        while(h2.next!=null)
        {
            h2 = h2.next;
        }
        h2.next = endb;
        return list1;
    }
}