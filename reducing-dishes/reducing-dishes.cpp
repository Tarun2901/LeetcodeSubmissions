class Solution {
public:
    
    
        int solve(vector<int>& arr,int idx,int n,int tt,vector<vector<int>>& dp)
    {
        if(idx == n)
        {
            return dp[idx][tt] = 0;
        }
        
        if(dp[idx][tt]!=-1)
        {
            return dp[idx][tt];
        }
        //exclude
        int exclude = 0;
        int include = 0;
      
        exclude = max(exclude,solve(arr,idx+1,n,tt,dp));
        include = max(include,tt*arr[idx] + solve(arr,idx+1,n,tt+1,dp));
          
        return dp[idx][tt] = max(include,exclude);
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        int idx = 0;
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        vector<int> visited(n,0);
        vector<vector<int>> dp(n+1,vector<int>(n+2,-1));
        int tt = 1;
        int ans = solve(satisfaction,0,n,tt,dp);
        return ans;
    }
};