class Solution {
public:
    
    int solve(int idx,string& s,int n,vector<int>& dp)
    {
        if(idx == n)
        {
            return dp[idx] = 1;
        }
        
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        int a = 0;
        
        if(s[idx] >= '1' && s[idx] <= '9')
        {
            a+= solve(idx+1,s,n,dp);
        }
        if(idx!=n-1 && (s.substr(idx,2)>="10" && s.substr(idx,2)<="26"))
        {
            a+= solve(idx+2,s,n,dp);
        }
        
        return dp[idx] = a;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        
        int idx = 0;
        vector<int> dp(n+1,-1);
        int ans = solve(idx,s,n,dp);
        return ans;
    }
};