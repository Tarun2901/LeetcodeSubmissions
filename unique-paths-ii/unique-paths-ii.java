class Solution {
    public int uniquePathsWithObstacles(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int sr = 0;
        int sc = 0;
        int er = m-1;
        int ec = n-1;
        int[][] dp = new int[m][n];
        for(int i = er;i>=sr;i--)
        {
            for(int j = ec;j>=sc;j--)
            {   if(grid[sr][sc]==1)
                {
                    return 0;
                }
                if(i == er && j == ec)
                {
                    dp[i][j] = 1;
                    continue;
                }
       
                int count = 0;
            //vertical
                if(i+1<=er && grid[i+1][j] == 0)
                {
                    count+= dp[i+1][j];
                }
            //horizontal
            if(j+1<=ec && grid[i][j+1] == 0)
            {
                 count+= dp[i][j+1];
            }

            dp[i][j] = count;
         }
        }
        return dp[sr][sc];
    }
}