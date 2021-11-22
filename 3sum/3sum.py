class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ls = []
        st = set()
        if len(nums) == 0:
            return ls
        nums = sorted(nums);
        for i in range(0,len(nums)-2):
            j = i+1;
            k = len(nums) - 1;
            target = -nums[i];
            while j<k:
                sm = nums[j] + nums[k];
                if sm == target:
                    l = [nums[i],nums[j],nums[k]];
                    l = sorted(l)
                    if tuple(l) not in st:
                        ls.append(l);
                        st.add(tuple(l));
                    
                    j+=1;
                    k-=1;
                elif sm > target:
                    k-=1;
                elif sm < target:
                    j+=1;
        
        return ls;
            