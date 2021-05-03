class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
       vector<int>ans(nums.size(),0);
        for(int i = 0;i<nums.size();i++)
        {   int a = nums[i];
            for(int j = 0;j<nums.size();j++)
            {
                if(nums[i]>nums[j])
                {
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};