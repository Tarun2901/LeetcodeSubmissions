class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        m = dict()
        for i in range(0,len(nums)):
            ele = nums[i]
            if ele in m:
                return True
            else:
                m[ele] = True
            
        return False
            
        