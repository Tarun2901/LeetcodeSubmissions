class Solution {
public:
    int solve(int n,vector<int>& cost,vector<int>& dp)
    {
        if(n<0)
        {
            return 0;
        }
        if(n == 0 || n==1)
        {
            return dp[n] = cost[n];
        }
        if(dp[n] !=0)
        {
            return dp[n];
        }
        return dp[n] = cost[n]+min(solve(n-1,cost,dp),solve(n-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,0);
        return min(solve(n-1,cost,dp),solve(n-2,cost,dp));
    }
};