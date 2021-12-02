# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        lst = []
        p = head;
        while p!=None:
            lst.append(p.val);
            p=p.next;
        print(lst)
        mult = 1;
        num = 0;
        for i in range(len(lst)-1,-1,-1):
            if lst[i] == 1:
                num+= mult;
            mult*=2;
        return num;