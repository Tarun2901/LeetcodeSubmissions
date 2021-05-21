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
    
     public int length(ListNode head){

        int len = 0;

        ListNode curr = head;

        while(curr!=null){

            curr = curr.next;
            len++;
        }
        return len;
    }
    public ListNode addFirst(ListNode head, ListNode toAdd){
        if(head==null){
            head = toAdd;
            toAdd.next = null;
            return head;
        }
        toAdd.next = head;
        head = toAdd;
        return head;
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        if(k == 0){
            return head;
        }
        if(head==null || head.next==null){
            return head;
        }
        int len = length(head);
        ListNode oh = null;
        ListNode ot = null;
        ListNode th = null;
        ListNode tt = null;
        ListNode curr = head;
        while(len >= k){
            for(int i = 0; i < k; i++){
                ListNode next = curr.next;
                if(th==null){
                    tt = curr;
                }
                // curr->next = NULL;
                th = addFirst(th, curr);
                len--;
                curr = next;
            }
            if(oh==null){
                oh = th;
                ot = tt;
            }
            else{
                ot.next = th;
                ot = tt;
            }
            th = null;
            tt = null;
            
        }
        if(curr!=null){
            ot.next = curr;
            
        }
        else{
            ot.next = null;
        }
        return oh;
    }
}