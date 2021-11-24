class Solution:
    def insert(self, intr,newInt):
        pos = 0
        status = False
        for i in range(0,len(intr)):
            if newInt[0]<=intr[i][0]:
                pos = i
                status = True
                break;
        if status == False:
            pos = len(intr);
        intr.insert(pos,newInt)
        print(intr);
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
        
        