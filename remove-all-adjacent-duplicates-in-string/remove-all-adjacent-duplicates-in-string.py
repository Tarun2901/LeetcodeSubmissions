class Solution:
    def removeDuplicates(self, s: str) -> str:
        ls = []
        for c in s:
            if len(ls)>0 and ls[-1]==c:
                ls.pop()
            else:
                ls.append(c)
        return "".join(ls)

            
        