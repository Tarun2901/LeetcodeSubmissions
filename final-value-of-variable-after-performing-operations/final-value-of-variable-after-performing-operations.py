class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        x = 0;
        for st in operations:
            if st == "++X" or st == "X++":
                x+=1;
            elif st == "X--" or st == "--X":
                x-=1;
        return x
        