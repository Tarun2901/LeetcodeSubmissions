# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head;
        if not head.next:
            return head;
        
        nxt = head.next;
        reverseHead = self.reverseList(head.next);
        nxt.next = head;
        head.next = None;
        return reverseHead;
        