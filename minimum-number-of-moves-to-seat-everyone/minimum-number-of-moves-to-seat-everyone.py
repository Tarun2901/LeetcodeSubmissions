class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        seats.sort();
        students.sort();
        
        ans = 0;
        
        for x,y in zip(seats,students):
            ans+=abs(y-x);
            
        return ans;