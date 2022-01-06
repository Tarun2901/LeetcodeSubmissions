class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        hp=[]
        for z in matrix:
            for el in z:
                if len(hp)<k or -el>(hp[0]):
                    heapq.heappush(hp,-el)
                if len(hp)>k:
                    heapq.heappop(hp)
        
        return -hp[0]
        