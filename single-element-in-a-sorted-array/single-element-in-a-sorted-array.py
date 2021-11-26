class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        lo = 0;
        hi = len(nums)-1
        if len(nums) == 1:
            return nums[0]
        while lo<=hi:
            mid = (lo+hi)//2
            if mid==0:
                if nums[mid] != nums[mid+1]:
                    return nums[mid];
            elif mid == len(nums)-1:
                if nums[mid] != nums[mid-1]:
                    return nums[mid];
            elif nums[mid] == nums[mid+1]:
                if mid%2 == 0:
                    lo = mid+1;
                else:
                    hi = mid-1;
            elif nums[mid] == nums[mid-1]:
                if mid%2==0:
                    hi = mid-1;
                else:
                    lo = mid+1;
            else:
                return nums[mid];
                