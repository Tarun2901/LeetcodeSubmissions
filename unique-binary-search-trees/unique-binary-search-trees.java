class Solution {
      int findCatalan(int n) 
    {
        //code here
        int N = 1000000007;
        int[] dp = new int[n+1];
        dp[0] = dp[1] = 1;
        for(int i = 2;i<=n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                dp[i] = (dp[i]+ ((dp[j])*(dp[i-j-1])));
            }
        }
        return dp[n];
    }
    public int numTrees(int n) {
        return (int)findCatalan(n);   
    }
}