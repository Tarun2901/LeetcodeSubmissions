class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq,hp = Counter(nums),[]
        for ele,count in freq.items():
            heapq.heappush(hp,(count,ele));
            if len(hp)>k:
                heapq.heappop(hp);
        return [x[1] for x in hp]
        