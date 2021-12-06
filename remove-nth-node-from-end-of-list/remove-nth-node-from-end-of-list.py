# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        start = ListNode(0);
        slow,fast = start,start;
        slow.next = head;
        for i in range(0,n+1):
            fast = fast.next;
        while fast:
            slow = slow.next;
            fast = fast.next;
        slow.next = slow.next.next;
        return start.next;