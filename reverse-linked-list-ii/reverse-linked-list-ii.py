# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if head == None:
            return head;
        fake = ListNode(0,None);
        fake.next = head;
        pre = fake;
        for i in range(0,left-1):
            pre=pre.next;
        curr = pre.next;
        nxt = curr.next;
        for i in range(0,right-left):
            curr.next = nxt.next;
            nxt.next = pre.next;
            pre.next = nxt;
            nxt = curr.next;
        return fake.next;