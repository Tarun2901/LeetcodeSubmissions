class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int posi = 0;
        int neg = 1;

        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                ans[posi] = nums[i];
                posi+=2;
            }
            else
            {
                ans[neg] = nums[i];
                neg+=2;
            }
        }
        
        return ans;
    }
};