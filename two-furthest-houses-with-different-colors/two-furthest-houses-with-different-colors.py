class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        ans = 0
        for i in range(0,len(colors)):
            ele = colors[i]
            if ele!=colors[0]:
                ans = max(ans,i);
            if ele!=colors[len(colors)-1]:
                ans = max(ans,len(colors)-1-i)
        
        return ans;
            
        