class Solution {
public:
    int dp[101][101];
    int solve(vector<int>& arr,int i,int j)
    {
       if(i>=j)
       {
           return 0;
       }
       if(dp[i][j]!=-1)
       {
           return dp[i][j];
       }
       int an = INT_MAX;
       for(int k = i;k<=j-1;k++)
       {
           int tempans = solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
           if(an>tempans)
           {
               an = tempans;
           }
       }
       return dp[i][j] = an;
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,-1,sizeof dp);
        int n = values.size();
        return solve(values,1,n-1);
    }
};