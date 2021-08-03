class Solution {
public:
    
  
    int solve(int idx, vector<int>& arr,int n,unordered_map<int,int>& dp)
    {
        if(idx == n-1)
        {
            return dp[idx] = 0;
        }
         if(idx>=n)
        {
            return INT_MAX-1;
        }
        if(arr[idx] == 0)
        {
            return dp[idx] = 1e5;
        }
      
        if(dp[idx]!=0)
        {
            return dp[idx];
        }
       

        int mn = 1e6;
        
        for(int i = 1;i<=arr[idx];i++)
        {
            mn = min(mn,1 + solve(idx+i,arr,n,dp));
        }
        return dp[idx] = (mn == 1e6?-1:mn);
    }
    
    int jump(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)
        {
            return 0;
        }
        unordered_map<int,int> dp;
        return solve(0,arr,n,dp);
    }
};