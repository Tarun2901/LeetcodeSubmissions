class Solution {
    public int uniquePaths(int m, int n) {
        int sr = 0;
        int sc = 0;
        int er = m-1;
        int ec = n-1;
        int[][] dp = new int[m][n];
        for(int i = er;i>=sr;i--)
        {
            for(int j = ec;j>=sc;j--)
            {
                if(i == er && j == ec)
                {
                    dp[i][j] = 1;
                    continue;
                }
       
                int count = 0;
            //vertical
                if(i+1<=er)
                {
                    count+= dp[i+1][j];
                }
            //horizontal
            if(j+1<=ec)
            {
            count+= dp[i][j+1];
            }

            dp[i][j] = count;
         }
        }
        return dp[sr][sc];
    }
}