class Solution {
public:
    
    int helper(vector<int>& nums,int target,int asf,vector<int>& dp)
    {   if(asf == target)
         {
            return 1; 
         }
         else if(asf>target)
         {
             return 0;
         }
        if(dp[asf]!=-1)
        {
            return dp[asf];
        }
        int count = 0;
        for(int i = 0;i<nums.size();i++)
        {  if(asf+nums[i]<=target)
          {
             count+= helper(nums,target,asf+nums[i],dp);
          }
        }
        dp[asf] = count;
        return count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target);
        std::fill(dp.begin(),dp.end(),-1);
        int ans = helper(nums,target,0,dp);
       
        return ans;
    }
};