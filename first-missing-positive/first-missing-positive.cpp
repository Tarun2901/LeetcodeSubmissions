class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> missing(n+1,0);
        
        for(int i = 0;i<n;i++)
        {
            if(nums[i]>=1 && nums[i]<=n)
            {
                missing[nums[i]] = 1;
            }
        }
        
        
        for(int i = 1;i<n+1;i++)
        {
            if(missing[i] == 0)
            {
                return i;
            }
        }
        
        return n+1;
    }
};