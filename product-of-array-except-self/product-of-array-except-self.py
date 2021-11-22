class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ans= [1]*len(nums);
        n = len(nums);
        lprod = 1;
        rprod = 1;
        for i in range(0,n):
            ans[i] = lprod;
            lprod*=nums[i];
        
        for i in range(n-1,-1,-1):
            ans[i]*=rprod;
            rprod*=nums[i];
        
        return ans;
            