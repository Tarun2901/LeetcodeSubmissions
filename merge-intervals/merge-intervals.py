class Solution:
    def merge(self, intr: List[List[int]]) -> List[List[int]]:
        intr = sorted(intr,key = lambda x:x[0])
        ans =[]
        curr = intr[0];
        for i in range(1,len(intr)):
            nextsp = intr[i][0]
            nextep = intr[i][1]
            if curr[1]>=nextsp:
                if curr[1]<nextep:
                    curr = [curr[0],nextep]
            else:
                ans.append(curr);
                curr = intr[i]
        ans.append(curr)
        return ans
        