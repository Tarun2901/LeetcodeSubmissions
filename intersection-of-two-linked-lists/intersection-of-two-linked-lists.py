# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        temp1 = headA;
        temp2 = headB;
        len1 = 0;
        len2 = 0;
        while temp1:
            temp1 = temp1.next;
            len1+=1;
        while temp2:
            temp2 = temp2.next;
            len2+=1;
            
        if len1>len2:
            diff = len1-len2;
            temp1 = headA;
            for i in range(diff):
                temp1 = temp1.next;
            temp2 = headB;
            while temp1 and temp2:
                if temp1 is temp2:
                    return temp1;
                temp1 = temp1.next;
                temp2 = temp2.next;
        else:
            diff = len2-len1;
            temp2 = headB;
            for i in range(diff):
                temp2 = temp2.next;
            temp1 = headA;
            while temp1 and temp2:
                if temp1 is temp2:
                    return temp1;
                temp1 = temp1.next;
                temp2 = temp2.next;