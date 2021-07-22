class Solution {
    
    
    public int solve(int[][] grid,int x1,int y1,int x2,int y2,int n,int[][][][] dp)
    {
        if(x1>=n || y1>=n || x2>=n || y2>=n || grid[x1][y1] == -1 || grid[x2][y2] == -1)
        {
            return -(int)(1e9);
        }
        if(dp[x1][y1][x2][y2]!=-1)
        {
            return dp[x1][y1][x2][y2];
        }
        if(x1 == n-1 && y1 == n-1)
        {
            return dp[x1][y1][x2][y2] = grid[x1][y1];
        }
     
        int ans = 0;
        
        if(x1 == x2 && y1 == y2)
        {
            ans+= grid[x1][y1];
        }
        else
        {
            ans+= grid[x1][y1] + grid[x2][y2];
        }
        
        int temp1 = solve(grid,x1+1,y1,x2+1,y2,n,dp);
        int temp2 = solve(grid,x1,y1+1,x2,y2+1,n,dp);
        int temp3 = solve(grid,x1+1,y1,x2,y2+1,n,dp);
        int temp4 = solve(grid,x1,y1+1,x2+1,y2,n,dp);
        ans = ans + Math.max(Math.max(temp1,temp2),Math.max(temp3,temp4));
        return dp[x1][y1][x2][y2] = ans;
    }
    public int cherryPickup(int[][] grid) {
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
        
        int n = grid.length;
        int[][][][] dp = new int[n][n][n][n];
        for(int[][][] r:dp)
        {
            for(int[][] x:r)
            {
                for(int[]y:x)
                {
                    Arrays.fill(y,-1);
                }
            }
        }
        int soln = solve(grid,x1,y1,x2,y2,n,dp);
        return Math.max(soln,0);
    }
}