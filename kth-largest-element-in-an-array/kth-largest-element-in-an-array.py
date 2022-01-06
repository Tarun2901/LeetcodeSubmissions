class Solution:
    def findKthLargest(self, arr: List[int], k: int) -> int:
        hp = []
        for el in arr:
            if len(hp)<k or el>hp[0]:
                heapq.heappush(hp,el)
            if len(hp)>k:
                heapq.heappop(hp)
        return hp[0];
        