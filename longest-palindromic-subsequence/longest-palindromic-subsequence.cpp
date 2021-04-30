class Solution {
public:
    int lcs(string s1,string s2, int x, int y)
    {
        int dp[x+1][y+1];
        for(int i = 0;i<x+1;i++)
        {
            for(int j = 0;j<y+1;j++)
            {
                if(i == 0||j==0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 1;i<x+1;i++)
        {
            for(int j = 1;j<y+1;j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[x][y];
    }
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        int n = s.length();
        reverse(s.begin(),s.end());
        string q = s;
        int ans = lcs(s1,q,n,n);
        return ans;
    }
};