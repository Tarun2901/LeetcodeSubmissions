class Solution {
public:
    
    
    int minimise(int sr,int sc,int er,int ec,vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        if(sr == er && sc == ec)
        {
            return dp[sr][sc] = grid[sr][sc];
        }
        if(dp[sr][sc]!=0)
        {
            return dp[sr][sc];
        }
        int a = INT_MAX;
        int b = INT_MAX;
        int cost = INT_MAX;
        if(sr+1<=er)
        {
            a =minimise(sr+1,sc,er,ec,grid,dp);
        }
        if(sc+1<=ec)
        {
            b =minimise(sr,sc+1,er,ec,grid,dp);
        }
        
        cost = min(a,b);
        return dp[sr][sc] = cost+grid[sr][sc];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int sr = 0;
        int sc = 0;
        int er = grid.size()-1;
        int ec = grid[0].size()-1;
        vector<vector<int>> dp(er+1,vector<int>(ec+1,0));
        int ans = minimise(sr,sc,er,ec,grid,dp);
        return ans;
    }
};