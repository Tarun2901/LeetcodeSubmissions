# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        temp=head;
        greater = ListNode(-1);
        itr1 = greater;
        smaller = ListNode(-1);
        itr2 = smaller;
        while temp:
            store = temp;
            temp = temp.next;
            if store.val<x:
                itr2.next = store;
                itr2 = itr2.next;
                itr2.next = None;
            else:
                itr1.next = store;
                itr1 = itr1.next;
                itr1.next = None;
        itr2.next = greater.next;
        return smaller.next;