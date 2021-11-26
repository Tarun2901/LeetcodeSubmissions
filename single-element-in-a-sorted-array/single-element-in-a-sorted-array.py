class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        st = [-1]
        for num in nums:
            if st[-1] == num:
                st.pop();
            else:
                st.append(num)
        return st[-1]