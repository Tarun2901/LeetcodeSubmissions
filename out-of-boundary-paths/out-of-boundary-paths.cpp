#include <math.h> 
#define mod 1000000007
class Solution {
public:
    int solve(int m,int n,int moves,int maxMove,int i,int j,vector<vector<vector<int>>>&dp)
    {
        
        if(i<0 || j<0 || i>=m || j>=n)
        {
            return 1;
        }
        if(dp[i][j][moves]>=0)
        {
            return dp[i][j][moves];
        }
        int ans = 0;
        
        if(moves<maxMove)
        {
        int t1 = solve(m,n,moves+1,maxMove,i+1,j,dp);
        int t2 = solve(m,n,moves+1,maxMove,i-1,j,dp);
        int t3 = solve(m,n,moves+1,maxMove,i,j+1,dp);
        int t4 = solve(m,n,moves+1,maxMove,i,j-1,dp);
        ans = (((t1%mod+t2%mod)%mod)+(t3%mod+t4%mod)%mod)%mod;
        }
        return dp[i][j][moves]=ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return solve(m,n,0,maxMove,startRow,startColumn,dp);
    }
};