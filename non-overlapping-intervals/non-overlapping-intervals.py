class Solution:
    def eraseOverlapIntervals(self, intr: List[List[int]]) -> int:
        intr = sorted(intr,key = lambda x:x[1]);
        curr = intr[0];
        ans =0
        for i in range(1,len(intr)):
            nextsp = intr[i][0];
            nextep = intr[i][1];
            if curr[1]>nextsp:
                ans+=1
            else:
                curr = intr[i];
     
    
        return ans
                