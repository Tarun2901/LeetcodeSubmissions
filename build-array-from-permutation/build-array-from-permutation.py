class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        n = len(nums);
        lst = []
        for i in range(n):
            lst.append(nums[nums[i]]);
        
        return lst;