class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        rSum = [];
        rS = 0;
        for i in range(0,len(nums)):
            rS+= nums[i];
            rSum.append(rS);
        return rSum