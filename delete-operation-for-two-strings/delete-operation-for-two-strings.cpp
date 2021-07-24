class Solution {
public:
    
     int solve(string &text1,string &text2,int n,int m,vector<vector<int>>& dp)
    {
        if(n == 0 || m == 0)
        {
            return dp[n][m] = 0;
        }
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        if(text1[n-1] == text2[m-1])
        {
            //(n-1)th character has matched and hence we will decrement both n and m
            return dp[n][m] = 1 + solve(text1,text2,n-1,m-1,dp);    
        }
        else
        {
            return dp[n][m] = max(solve(text1,text2,n-1,m,dp),solve(text1,text2,n,m-1,dp));
        }
    }
    
    int LCS(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int soln = solve(text1,text2,n,m,dp);
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int lcs = LCS(word1,word2);
        return (word1.size()+word2.size()-2*lcs);
    }
};