class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 0;
        if(nums.size()==0)
        {
            return 0;
        }
        if(nums.size()==1)
        {
            return 1;
        }
        for(int i = 0;i<nums.size()-1;i++)
        {   int countlocal = 1;
            if(nums[i+1]>nums[i])
            {
                countlocal++;
            }
            else
            {
                count = max(count,countlocal);
            }
            for(int j = i+1;j<nums.size()-1;j++)
            {
                if(nums[j]<nums[j+1])
                {
                    countlocal++;
                }
                else
                {
                    break;
                }
            }
         count = max(count,countlocal);
        }
        return count;
    }
};