class Solution {
public:
    int lcs(string t,string s,int m,int n)
    {
        int dp[m+1][n+1];
        for(int i = 0;i<m+1;i++)
        {
            for(int j =0;j<n+1;j++)
            {
                if(i==0||j==0)
                {
                dp[i][j] = 0;
                }
            }
        }
        for(int i = 1;i<m+1;i++)
        {
            for(int j = 1;j<n+1;j++)
            {
                if(t[i-1]==s[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    bool isSubsequence(string s, string t) {
        int m = t.length();
        int n = s.length();
        int ans = lcs(t,s,m,n);
        if(ans == n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};