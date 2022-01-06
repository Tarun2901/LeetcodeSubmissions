class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        hp = []
        
        for point in points:
            x = point[0]
            y = point[1]
            print(x,y)
            dist = int((x**2 + y**2));
            print(dist)
            if len(hp)<k or (-dist)>(hp[0][0]):
                print("Entered 1")
                heapq.heappush(hp,(-dist,point));
            if len(hp)>k:
                print("Entered 2")
                heapq.heappop(hp)
        
        return [x[1] for x in hp];