class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,1);
        
        for(int i = 0;i<n;i++)
        {   
            for(int j = 0;j<i;j++)
            {
                if(arr[j]<arr[i])
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }
        int mx = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            mx = max(mx,dp[i]); 
        }
        
        return mx;
    }
};