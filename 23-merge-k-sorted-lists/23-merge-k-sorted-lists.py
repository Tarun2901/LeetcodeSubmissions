# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        heap = []
        for head in lists:
            if head:
                heapq.heappush(heap,(head.val,head));
        ans = ListNode()
        p = ans;
        while len(heap)>0:
            n = heapq.heappop(heap)[1]
            p.next = n;
            p = n; #move p to next element
            if n.next:
                heapq.heappush(heap,(n.next.val,n.next));
        
        return ans.next;
        