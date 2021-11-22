class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        p = -1;
        #Find first decreasing element
        for i in range(len(nums)-2,-1,-1):
            if nums[i]<nums[i+1]:
                p = i;
                break;
        # Find just greater element than p on it's right
        justGreater = -1;
        for i in range(len(nums)-1,p,-1):
            if nums[p]<nums[i]:
                justGreater = i;
                break;
        
        if p!=-1 and justGreater!=-1:
            nums[p],nums[justGreater] = nums[justGreater],nums[p];
        
        #Reverse
        
        j = p+1;
        k = len(nums) - 1;
        while(j<k):
            nums[j],nums[k] = nums[k],nums[j];
            j+=1;
            k-=1;
        
        
        
        
            
        