class Solution {
public:
    
    bool isSubsetSum(vector<int>& arr,int sum, int n)
    {
        bool dp[n+1][sum+1];
        for(int i = 0;i<n+1;i++)
        {
            for(int j = 0;j<sum+1;j++)
            {
                if(i == 0)
                {
                    dp[i][j] = false;
                }
                if(j == 0)
                {
                    dp[i][j] = true;
                }
            }
        }
        
        for(int i = 1;i<n+1;i++)
        {
            for(int j = 1;j<sum+1;j++)
            {
                 if(arr[i-1]<=j)
                 {
                     dp[i][j] = dp[i-1][j-arr[i-1]]||dp[i-1][j];
                 }
                 else
                 {
                     dp[i][j] = dp[i-1][j];
                 }
            }
        }
        return dp[n][sum]; 
    }
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        for(int i = 0;i<size;i++)
        {
            sum = nums[i]+sum;
        }
        if(sum%2!=0)
        {
            return false;
        }
        else
        {
            if(isSubsetSum(nums,sum/2,size) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};