class Solution {
    
    public int cSMemo(int n, int[] dp)
    {
        if(dp[n]!=0)
        {
            return dp[n];
        }
        int ans1 = cSMemo(n-1,dp);
        int ans2 = cSMemo(n-2,dp);
        int ans = ans1+ans2;
        dp[n] = ans;
        return ans;
        }
    public int climbStairs(int n) {
       int[] dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 1;
        return cSMemo(n,dp);
    }
}