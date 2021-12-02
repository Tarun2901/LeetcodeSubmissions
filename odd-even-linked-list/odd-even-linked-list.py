# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head;
        
        odd = head;
        stored = head.next;
        even = head.next;
        
        while odd and even and even.next:
            oddNxt = odd.next.next;
            evenNxt = even.next.next;
            odd.next = oddNxt;
            even.next = evenNxt;
            odd = odd.next;
            even = even.next;
        odd.next = stored;
        return head;
            
            
        